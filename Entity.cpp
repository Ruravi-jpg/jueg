#include "Entity.h"

#include <iostream>

Entity::Entity() : timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(5), onGround(false), onPlataform(0), id(-1)
{
	position = Vector2();
	AList = AnimationList();
	direction = Vector2();
}

Entity::Entity(Vector2& position, AnimationList& Alist, int &id) : position(position), AList(Alist), timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(5), onGround(false), onPlataform(0), id(-1)
{
	direction = Vector2();
}

Entity::Entity(Vector2& position, AnimationList& Alist, float& speed, int& id) : position(position), AList(Alist), timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(speed), onGround(false), onPlataform(0), id(-1)
{
	direction = Vector2();
}

Entity::Entity(AnimationList& Alist, int& id) : AList(AList), timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(5), onGround(false), onPlataform(0), id(-1)
{
	position = Vector2();
	direction = Vector2();
}

Entity::Entity(const Entity& copy)
{
	this->timer = copy.timer;
	this->frame = copy.frame;
	this->gravity = copy.gravity;
	this->horizontalSpeed = copy.horizontalSpeed;
	this->speed = copy.speed;
	this->onGround = copy.onGround;
	this->onPlataform = copy.onPlataform;
	this->position = copy.position;
	this->AList = copy.AList;
	this->direction = copy.direction;
}



void Entity::setSpeed(float& speed)
{
	this->speed = speed;
}

Vector2 Entity::getPosition() const
{
	int height = AList.getAnimation(0).getTexture().height;
	Vector2 pos = { position.x, position.y + height };
	return pos;
	//return position;
}

float Entity::getSpeed() const
{
	return speed;
}

void Entity::setOnground(bool state)
{
	onGround = state;
}

void Entity::setPos(Vector2& nPos)
{
	Vector2 newPos{nPos.x, nPos.y - AList.getAnimation(0).getTexture().height};
	this->position = newPos;
	/*Vector2 npos = { nPos.x, nPos.y };
	this->position = npos;*/
}

bool Entity::getOnground() const
{
	return onGround;
}

int Entity::getOnPlataform() const
{
	return onPlataform;
}

void Entity::setOnPlataform(int onPlat)
{
	onPlataform = onPlat;
}

void Entity::notOnPlatafrom()
{
	this->position.y += speed * GetFrameTime();
	this->speed += gravity * GetFrameTime();
	//setOnground(false);

}

void Entity::moveEntity()
{
	position.x += horizontalSpeed * direction.x * GetFrameTime();
}

void Entity::animateEntity()
{
	int walk = 2;
	int idle = 0;
	int jump = 1;
	if (isMoving())
	{
		state = AnimationState::Walking;
	}
	if (!isMoving()) {
		state = AnimationState::Idle;
	}
	if (!onGround) {
		state = AnimationState::Jumping;
	}

	switch (state)
	{
	case AnimationState::Walking:
		AList.getAnimation(walk).animate(position, timer, frame);
		break;
	case AnimationState::Idle:
		AList.getAnimation(idle).animate(position, timer, frame);
		break;
	case AnimationState::Jumping:
		AList.getAnimation(jump).animate(position, timer, frame);
		break;
	default:
		break;
	}
}

void Entity::update()
{

	moveEntity();
	updateHitbox();
	animateEntity();
	//checkCollision();
}

bool Entity::isMoving() const
{
	if (direction.x != 0) { return true; }

	return false;
}

void Entity::setDirection(Vector2& nDir)
{
	this->direction = nDir;
}

Vector2 Entity::getDirection() const
{
	return direction;
}

void Entity::setList(AnimationList& nList)
{
	AList = nList;
}

void Entity::setPosition(Vector2& position)
{
	this->position = position;
}

void Entity::unload()
{
	AList.unloadText();
}

AnimationList Entity::getList() const
{
	return AList;
}

int Entity::getId() const
{
	return id;
}

void Entity::setId(int& id)
{
	this->id = id;
}

void Entity::updateHitbox()
{
	int entityWidth = (getList().getAnimation(0).getTexture().width / getList().getAnimation(0).getCols()) / 2;
	int entituHeight = (getList().getAnimation(0).getTexture().height);

	this->hitbox = { float(getPosition().x), float(getPosition().y), float(entityWidth), float(entituHeight) };
}

Rectangle Entity::getHitbox() const
{
	return hitbox;
}

Entity::~Entity()
{
	//unload();
}
