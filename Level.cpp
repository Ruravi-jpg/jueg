#include "Level.h"



Level::Level(int &id) : id(id), isUnloading(false)
{
	this->player = nullptr;
	this->enemies = std::vector<Enemy*>();
	this->tiles = std::vector<Tile>();
	this->entities = std::vector<Entity*>();

	setLevelData();

}

Level::~Level()
{
}

void Level::loadLevel(int& id)
{
	unloadLevelData();
	this->id = id;
	setLevelData();
	this->isUnloading = false;
}

void Level::setId(int id)
{
	this->id = id;
}

void Level::setPlayer(Player& player)
{
	this->player = &player;
}

void Level::setEnemies(std::vector<Enemy>& enemies)
{
	int id = 1;
	for (int i = 0; i < enemies.size(); i++) {
		//enemies[i].setId(id);
		this->enemies.push_back(&enemies[i]);
	}
}

void Level::setTiles(std::vector<Tile>& tiles)
{
	for (int i = 0; i < tiles.size(); i++) {
		this->tiles.push_back(tiles[i]);
	}
}

void Level::setLevelData()
{
	//setPlayer(player);
	//setEnemies(enemies);
	//setTiles(tiles);

	LevelLoader::loadData(this->id);
	setPlayer(LevelLoader::get().player);
	setTiles(LevelLoader::get().tiles);
	setEnemies(LevelLoader::get().enemies);

	entities.push_back(this->player);
	for (int i = 0; i < enemies.size(); i++) {
		entities.push_back(this->enemies[i]);
	}

}

void Level::drawTiles()
{
	for (Tile tile : tiles) {
		tile.drawTile();
	}
}

int Level::getId() const
{
	return id;
}

void Level::drawLevel()
{
	if (isUnloading) {
		return;
	}
	
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->update();
	}

	player->update();

	drawTiles();
	checkColl();

	if (IsKeyPressed(KEY_T)) {
		player->setHealth(3);
	}


}

void Level::unloadData()
{
	player->unload();
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->unload();
	}
}

void Level::checkColl()
{
	
		
	for ( int i = 0; i < entities.size(); i++)
	{
		Vector2 entityPos = entities[i]->getPosition();
		float zero = 0;
		entities[i]->setOnPlataform(0);

		int entityWidth = (entities[i]->getList().getAnimation(0).getTexture().width / entities[i]->getList().getAnimation(0).getCols())/2;
		/*int entituHeight = (entities[i]->getList().getAnimation(0).getTexture().height);

		Rectangle hitbox = { float(entities[i]->getPosition().x), float(entities[i]->getPosition().y), float(entityWidth), float(entituHeight) };*/

		//DrawRectangle(test.x, test.y - test.height, test.width*2, test.height, GREEN);

		for (Tile& tile : tiles)
		{
			int tileWidth = tile.getRect().width;
			
			if ( tile.getRect().x - entityWidth <= entityPos.x and
				tile.getRect().x + tileWidth >= entityPos.x
				and
				tile.getRect().y >= entityPos.y and
				tile.getRect().y < entityPos.y + entities[i]->getSpeed() * GetFrameTime() and (entities[i]->getOnPlataform() == 0))
			{
				Vector2 nPos = { entityPos.x, tile.getRect().y };
				entities[i]->setSpeed(zero);
				entities[i]->setPos(nPos);
				entities[i]->setOnground(true);
				entities[i]->setOnPlataform(1);

			}

			if (entities[i]->getId() == 1 and (CheckCollisionRecs(entities[i]->getHitbox(), tile.getRect()) ) and (tile.getRect().x  >= entities[i]->getHitbox().x or
				
				(entities[i]->getHitbox().x+ entities[i]->getHitbox().width) >= tile.getRect().x+tile.getRect().width ))
			{
				int tilepos = tile.getRect().y;
				Vector2 ndir = { -entities[i]->getDirection().x, 0 };
				entities[i]->setDirection(ndir);				
			}

		}

		if (entities[i]->getId() == 1) {
			int entityHeight = (entities[i]->getList().getAnimation(0).getTexture().height / entities[i]->getList().getAnimation(0).getRows()) / 2;

			if (CheckCollisionRecs(entities[i]->getHitbox(), player->getHitbox())){
				//std::cout << "collision" << std::endl;
			}
		}

		

	}
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getOnPlataform() == 0) {
			entities[i]->notOnPlatafrom();
		}
	}
}

void Level::unloadLevelData()
{
	isUnloading = true;
	tiles.clear();
	enemies.clear();
	entities.clear();
	LevelLoader::get().unloadData();

}


