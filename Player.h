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
	Player(AnimationList& list);
	Player(Vector2 &position, AnimationList& list);
	Player(Vector2 &position, AnimationList& list, float &speed);

	void update();

	void input();

	void unloadPlayer();

	~Player();

};

