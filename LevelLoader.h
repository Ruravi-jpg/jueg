#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include <vector>
#include <sstream>

#include <raylib.h>
#include "Tile.h"
#include "json.hpp"

using json = nlohmann::json;

class LevelLoader
{
public:
	//LevelLoader(const LevelLoader&) = delete;

	static LevelLoader& get();

	static void loadData(int &id);

	std::vector<Tile> tiles;

private:
	void IloadData(int& id);
	LevelLoader();

	json data;
};

