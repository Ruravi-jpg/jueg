#pragma once

#include "raylib.h"
#include "Player.h"
#include "Entity.h"
#include "Collisions.h"
#include "Tile.h"
#include "Enemy.h"

#include <vector>

#include <iostream>

class Level
{
private:

	int id;

	std::vector<Enemy*> enemies;
	std::vector<Tile> tiles;

	std::vector<Entity*> entities;
	
	Player* player;


	public:
		Level(int id);

		void setId(int id);
		void setPlayer(Player& player);
		void setEnemies(std::vector<Enemy>& enemies);
		void setTiles(std::vector<Tile>& tiles);

		void setLevelData(Player& player, std::vector<Enemy>& enemies, std::vector<Tile>& tiles);

		void drawTiles();

		int getId()const;

		void drawLevel();

		void unloadData();

		void checkColl();




};

