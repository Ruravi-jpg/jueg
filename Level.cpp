#include "Level.h"



Level::Level(int id) : id(id)
{
	this->player = nullptr;
	this->enemies = std::vector<Enemy*>();
	this->tiles = std::vector<Tile>();
	this->entities = std::vector<Entity*>();

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
	for (int i = 0; i < enemies.size(); i++) {
		this->enemies.push_back(&enemies[i]);
	}
}

void Level::setTiles(std::vector<Tile>& tiles)
{
	for (int i = 0; i < tiles.size(); i++) {
		this->tiles.push_back(tiles[i]);
	}
}

void Level::setLevelData(Player& player, std::vector<Enemy>& enemies, std::vector<Tile>& tiles)
{
	setPlayer(player);
	setEnemies(enemies);
	//setTiles(tiles);

	LevelLoader::loadData(this->id);
	setTiles(LevelLoader::get().tiles);

	entities.push_back(&player);
	//std::cout << "pushin player with id: " << player.getId() << std::endl;
	for (int i = 0; i < enemies.size(); i++) {
		entities.push_back(&enemies[i]);
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
	
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->update();
	}

	player->update();

	drawTiles();
	checkColl();


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

		for (Tile& tile : tiles)
		{
			int tileWidth = tile.getRect().width;
			
			if (tile.getRect().x - entityWidth <= entityPos.x and
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
		}

		if (entities[i]->getId() == 1) {
			int entityHeight = (entities[i]->getList().getAnimation(0).getTexture().height / entities[i]->getList().getAnimation(0).getRows()) / 2;

			if (entities[i]->getPosition().x - entityWidth <= player->getPosition().x and
				entityPos.x + entityWidth >= player->getPosition().x
				and
				entities[i]->getPosition().y - entityHeight <= player->getPosition().y and
				entityPos.y + entityHeight >= player->getPosition().y) {

					std::cout << "colliding with enemy " << i << std::endl;
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


