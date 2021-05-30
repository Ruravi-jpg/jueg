#include "Collisions.h"
#include <iostream>


Collisions::Collisions()
{
	tiles = std::vector<Tile>();
	entity = nullptr;
	entities = std::vector<Entity*>();

}

Collisions::Collisions(std::vector<Tile>& tiles, Entity& player)
{
	entity = &player;
	this->tiles.operator=(tiles);
}

void Collisions::drawColl()
{
	for (Tile tile : tiles) {
		tile.drawTile();
	}
}

void Collisions::calColl()
{
	
	
	/*for (Tile &tile : tiles)
	{
		Vector2 playerPos = entity->getPosition();
		float zero = 0;
		entity->setOnPlataform(0);

		if (tile.getRect().x <= playerPos.x and
			tile.getRect().x + tile.getRect().width >= playerPos.x and
			tile.getRect().y >= playerPos.y and
			tile.getRect().y < playerPos.y + entity->getSpeed() * GetFrameTime() and (entity->getOnPlataform() == 0))
		{
			Vector2 nPos = { playerPos.x, tile.getRect().y };
			entity->setSpeed(zero);
			entity->setPos(nPos);
			entity->setOnground(true);
			entity->setOnPlataform(1);

		}

	}
	

	if (entity->getOnPlataform() == 0) {
		entity->notOnPlatafrom();

	}*/

	for (Tile& tile : tiles)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			Vector2 playerPos = { entities[i]->getPosition().x, entities[i]->getPosition().y };
			float zero = 0;
			entities[i]->setOnPlataform(0);

			if (tile.getRect().x <= playerPos.x and
				tile.getRect().x + tile.getRect().width >= playerPos.x and
				tile.getRect().y >= playerPos.y and
				tile.getRect().y < playerPos.y + entities[i]->getSpeed() * GetFrameTime() and (entities[i]->getOnPlataform() == 0))
			{
				Vector2 nPos = { playerPos.x, tile.getRect().y };
				entities[i]->setSpeed(zero);
				entities[i]->setPos(nPos);
				entities[i]->setOnground(true);
				entities[i]->setOnPlataform(1);

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

void Collisions::update()
{
	drawColl();
	//calColl();
}

void Collisions::setPlayer(Player& player)
{
	//this->entity = &player;
	//this->entities.push_back(&player);
}

void Collisions::setTiles(std::vector<Tile>& tiles)
{
	this->tiles.operator=(tiles);
}

void Collisions::setEntities(std::vector<Entity>& entities)
{
	for (int i = 0; i < entities.size(); i++) {
		this->entities.push_back(&entities[i]);
	}
}

