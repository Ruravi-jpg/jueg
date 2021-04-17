#include "Tile.h"

Tile::Tile()
{
	rec = Rectangle();
	color = RED;
	blocking = 0;
}

Tile::Tile(Rectangle& rec, int blocking, Color color): blocking(blocking), color(color)
{
	this->rec = rec;
}

void Tile::drawTile()
{
	DrawRectangleRec(rec, color);
}

Rectangle Tile::getRect() const
{
	return rec;
}
