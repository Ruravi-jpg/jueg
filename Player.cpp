#pragma once

#include "Player.h"
#include <iostream>



Player::Player(AnimationList& list, int& id): moving(false), jumpSpeed(450), Entity(list, id)
{
	state = AnimationState::Idle;
}

Player::Player(Vector2& position, AnimationList& list, int& id) : moving(false), jumpSpeed(450), Entity(position, list, id)
{
	state = AnimationState::Idle;
}

Player::Player(Vector2& position, AnimationList& list, float& speed, int& id): moving(false), jumpSpeed(450), Entity(position, list, speed, id)
{
	state = AnimationState::Idle;
}


void Player::update()
{
	input();
	moveEntity();
    updateHitbox();
	animateEntity();
    
    //checkCollision();
}

void Player::input()
{
    Vector2 direction = { 0,0 };
    float jumpSpeed = -450;

    if (IsKeyDown(KEY_LEFT)) {
        //position.x -= horizontalSpeed * GetFrameTime();
        direction.x = -1;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        //position.x += horizontalSpeed * GetFrameTime();
        direction.x = 1;
    }
    if (IsKeyPressed(KEY_SPACE) and onGround) {
        //setOnground(false);
        Vector2 nPos = { getPosition().x, getPosition().y - 1 };
        setPos(nPos);
        setSpeed(jumpSpeed);
        setOnground(false);
        setOnPlataform(0);
    }

    setDirection(direction);
}

Player::Player() : moving(false), jumpSpeed(450), Entity()
{
    id = 0;
}



void Player::unloadPlayer()
{
	AList.unloadText();
}


Player::~Player()
{
	unloadPlayer();
}

