#pragma once
#include <iostream>
#include "Entity.h"
class Enemy : public Entity
{
private:
	float timer;
	float timeToCh;

public:
	Enemy();

	void update();

	void moveEnemy();
};

