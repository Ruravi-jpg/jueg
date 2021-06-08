#pragma once
#include "AnimationList.h"
#include "Tile.h"

enum class AnimationState
{
	Walking,
	Idle,
	Jumping
};

class Entity
{
protected:
	int id;
	Vector2 position;
	AnimationList AList;
	Vector2 direction;
	AnimationState state;
	float timer;
	int frame;
	int gravity;
	int horizontalSpeed;
	float speed;
	bool onGround;
	int onPlataform;

	std::vector<Tile> tiles;

public:
	Entity();
	Entity(Vector2& position, AnimationList& Alist, int& id);
	Entity(Vector2& position, AnimationList& Alist, float& speed, int& id);
	Entity(AnimationList& Alist, int& id);

	Entity(const Entity& copy);


	void setSpeed(float& speed);

	Vector2 getPosition()const;

	float getSpeed()const;

	void setOnground(bool state);

	void setPos(Vector2& nPos);

	bool getOnground()const;

	int getOnPlataform()const;

	void setOnPlataform(int onPlat);

	void notOnPlatafrom();

	void moveEntity();

	void animateEntity();

	virtual void update();

	bool isMoving()const;

	void setDirection(Vector2& nDir);

	void setList(AnimationList& nList);

	void setPosition(Vector2& position);

	void unload();

	void setTiles(std::vector<Tile> tiles);

	AnimationList getList()const;

	int getId()const;

	void setId(int& id);

	~Entity();
};

