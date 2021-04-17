#pragma once
#include "raylib.h"
#include "Entity.h"
#include "Tile.h"

#include <vector>

class Collisions
{
private:
	
	std::vector<Tile> tiles;
	Entity* entity;
	std::vector<Entity*> entities;

public:
	Collisions();
	Collisions(std::vector<Tile>& tiles , Entity& player);

	void drawColl();

	void calColl();

	void update();

	void setPlayer(Entity& player);
	void setTiles(std::vector<Tile>& tiles);
	void setEntities(std::vector<Entity>& entities);
};

