#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include <vector>
#include <sstream>

#include <raylib.h>
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "json.hpp"
#include "AnimationList.h"

using json = nlohmann::json;

class LevelLoader
{
public:
	//LevelLoader(const LevelLoader&) = delete;

	static LevelLoader& get();

	static void loadData(int &id);
	void unloadData();

	std::vector<Tile> tiles;
	std::vector<Enemy> enemies;
	Player player;
	Enemy enemy;


private:
	void IloadData(int& id);
	LevelLoader();
	void loadTiles(int &id);
	void loadEnemiesbase();
	void loadEnemiesLevel(int &id);
	void loadPlayerBase();
	void loadPlayerLevel(int& id);

	

	json data;
};

