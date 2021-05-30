#include "Enemy.h"

Enemy::Enemy() : Entity(), timer(0), timeToCh(1)
{
	horizontalSpeed = 100;
	Vector2 left = { -1,0 };
	direction = left;
}

void Enemy::update() 
{
	moveEntity();
	moveEnemy();
	animateEntity();
	//checkCollision();
}

void Enemy::moveEnemy()
{
	timer += GetFrameTime();

	if (timer >= timeToCh) {
		timer = 0;
		Vector2 ndir = { -direction.x, 0 };
		setDirection(ndir);
	}
}
