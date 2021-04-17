#pragma once

#include "Player.h"
#include <iostream>



Player::Player(AnimationList& list): moving(false), jumpSpeed(450), Entity(list)
{
	state = AnimationState::Idle;
}

Player::Player(Vector2& position, AnimationList& list) : moving(false), jumpSpeed(450), Entity(position, list)
{

	state = AnimationState::Idle;
}

Player::Player(Vector2& position, AnimationList& list, float& speed): moving(false), jumpSpeed(450), Entity(position, list, speed)
{
	state = AnimationState::Idle;
}


void Player::update()
{
	moveEntity();
	animateEntity();
}

Player::Player() : moving(false), jumpSpeed(450), Entity()
{
	

}


void Player::unloadPlayer()
{
	AList.unloadText();
}


Player::~Player()
{
	unloadPlayer();
}

