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
	int health;
	int score;

public:
	Player();
	Player(int& id);
	Player(AnimationList& list, int& id);
	Player(Vector2& position, AnimationList& list, int& id);
	Player(Vector2& position, AnimationList& list, float& speed, int& id);

	void update();

	void input();

	void unloadPlayer();

	int getHealth()const;
	int getScore()const;

	void setHealth(int health);
	void setScore(int score);


	~Player();

};

