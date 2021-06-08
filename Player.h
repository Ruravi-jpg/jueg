#pragma once

#include <vector>
#include "AnimationList.h"
#include "raylib.h"
#include "Entity.h"

class Player : public Entity
{
private:
	
	int jumpSpeed;
	bool moving;	

public:
	Player();
	Player(int& id);
	Player(AnimationList& list, int& id);
	Player(Vector2 &position, AnimationList& list, int& id);
	Player(Vector2 &position, AnimationList& list, float &speed, int& id);

	void update();

	void input();

	void unloadPlayer();

	~Player();

};

