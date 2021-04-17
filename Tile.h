#pragma once

#include "raylib.h"

class Tile
{
private:
	Rectangle rec;
	Color color;
	int blocking;


public:
	Tile();
	Tile(Rectangle& rec, int blocking, Color color);

	void drawTile();

	Rectangle getRect()const;
};

