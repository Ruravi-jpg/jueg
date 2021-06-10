#pragma once

#include "raylib.h"

class Tile
{
private:
	Rectangle rec;
	Color color;
	int blocking;
	int id;


public:
	Tile();
	Tile(Rectangle& rec, int blocking, Color color, int id);

	void drawTile();

	Rectangle getRect()const;

	void setId(int id);
	int getId()const;
};

