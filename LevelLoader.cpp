#include "LevelLoader.h"

LevelLoader& LevelLoader::get()
{
	static LevelLoader instance;
	return instance;
}

void LevelLoader::loadData(int &id)
{
	return get().IloadData(id);
}

void LevelLoader::IloadData(int& id)
{
	loadTiles(id);
	loadPlayerLevel(id);
	loadEnemiesLevel(id);

}

LevelLoader::LevelLoader()
{
	tiles =  std::vector<Tile>();
	player = Player();
	enemy = Enemy();
	loadPlayerBase();
	loadEnemiesbase();
}

void LevelLoader::loadTiles(int& id)
{

	std::stringstream path;
	path << "./LevelInfo/" << id << ".json";

	std::ifstream file(path.str());

	json Info;

	file >> Info;

	std::stringstream tile;

	for (int i = 1; i <= Info["Tiles"].size(); i++) {
		tile << "tile" << i;
		json auxJson = Info["Tiles"][tile.str()];

		Rectangle auxRec = { auxJson["x"], auxJson["y"], auxJson["Width"], auxJson["Height"] };
		Tile auxTile = { auxRec, 1, LIGHTGRAY };

		this->tiles.push_back(auxTile);

		tile.str(std::string());
	}

	

	file.close();
}

void LevelLoader::loadEnemiesbase()
{
	std::ifstream file("./EntityDataJson/Enemy.json");

	json enemyInfo;

	file >> enemyInfo;

	json AnimationInfo = enemyInfo["AnimationInfo"];

	std::vector<AnimationSt> enemyAnimations;

	for (json::iterator it = AnimationInfo.begin(); it != AnimationInfo.end(); it++) {
		std::string animName = it.key();
		std::string texturePath;
		int cols = 0;
		int rows = 0;
		int speed = 0;

		json animation = AnimationInfo[animName];

		for (json::iterator anim = animation.begin(); anim != animation.end(); anim++) {
			if (anim.key() == "Texture") {
				texturePath = anim.value();
			}
			if (anim.key() == "Col") {
				cols = anim.value();
			}
			if (anim.key() == "Rows") {
				rows = anim.value();
			}
			if (anim.key() == "Speed") {
				speed = anim.value();
			}
		}
		Texture2D auxText = LoadTexture(texturePath.c_str());
		AnimationSt aux(auxText, cols, rows, speed);

		enemyAnimations.push_back(aux);

	}
	AnimationList playerAnimationsList(enemyAnimations);
	enemy.setList(playerAnimationsList);

	file.close();
}

void LevelLoader::loadEnemiesLevel(int &id)
{
	std::stringstream path;
	path << "./LevelInfo/" << id << ".json";

	std::ifstream file(path.str());

	json Info;

	file >> Info;

	json enemyInfoLevel = Info["Enemies"];
	int Enemyx;
	int EnemyY;
	int idEnemy = 1;

	for (json::iterator it = enemyInfoLevel.begin(); it != enemyInfoLevel.end(); it++) {
		std::string enemy = it.key();

		json enemyInfo = enemyInfoLevel[enemy.c_str()];

		for (json::iterator curEnemy = enemyInfo.begin(); curEnemy != enemyInfo.end(); curEnemy++) {
			if (curEnemy.key() == "x") {
				Enemyx = curEnemy.value();
			}
			else {
				EnemyY = curEnemy.value();
			}
		}
		Enemy auxEnemy;
		AnimationList list(this->enemy.getList());
		auxEnemy.setList(list);
		Vector2 enemyPos = { Enemyx, EnemyY };
		auxEnemy.setPosition(enemyPos);
		auxEnemy.setId(idEnemy);
		this->enemies.push_back(auxEnemy);
	}
	
	file.close();

}

void LevelLoader::loadPlayerBase()
{

	std::ifstream file("./EntityDataJson/Player.json");

	json playerInfo;

	file >> playerInfo;

	json AnimationInfo = playerInfo["AnimationInfo"];

	std::vector<AnimationSt> playerAnimations;

	for (json::iterator it = AnimationInfo.begin(); it != AnimationInfo.end(); it++) {
		std::string animName = it.key();
		std::string texturePath;
		int cols = 0;
		int rows = 0;
		int speed = 0;

		json animation = AnimationInfo[animName];

		for (json::iterator anim = animation.begin(); anim != animation.end(); anim++) {
			if (anim.key() == "Texture") {
				texturePath = anim.value();
			}
			if (anim.key() == "Col") {
				cols = anim.value();
			}
			if (anim.key() == "Rows") {
				rows = anim.value();
			}
			if (anim.key() == "Speed") {
				speed = anim.value();
			}
		}
		Texture2D auxText = LoadTexture(texturePath.c_str());
		AnimationSt aux(auxText, cols, rows, speed);

		playerAnimations.push_back(aux);

	}
	AnimationList playerAnimationsList(playerAnimations);
	player.setList(playerAnimationsList);

	file.close();

}

void LevelLoader::loadPlayerLevel(int& id)
{
	std::stringstream path;
	path << "./LevelInfo/" << id << ".json";

	std::ifstream file(path.str());

	json Info;

	file >> Info;

	json playerInfoLevel = Info["Player"];
	int playerX;
	int playerY;

	for (json::iterator it = playerInfoLevel.begin(); it != playerInfoLevel.end(); it++) {
		if (it.key() == "x") {
			playerX = it.value();
		}
		else {
			playerY = it.value();
		}
	}
	Vector2 playerPos = { playerX, playerY };
	player.setPosition(playerPos);
	file.close();
}

void LevelLoader::unloadData()
{
	tiles.clear();
	enemies.clear();
}
