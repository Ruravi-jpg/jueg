#include "Tile.h"

Tile::Tile()
{
	rec = Rectangle();
	color = RED;
	blocking = 0;
	id = 0;
}

Tile::Tile(Rectangle& rec, int blocking, Color color, int id): blocking(blocking), color(color), id(id)
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

void Tile::setId(int id)
{
	this->id = id;
}

int Tile::getId() const
{
	return id;
}
