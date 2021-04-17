#include "Entity.h"

Entity::Entity() : timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(5), onGround(false), onPlataform(0)
{
	position = Vector2();
	AList = AnimationList();
	direction = Vector2();
}

Entity::Entity(Vector2& position, AnimationList& Alist) : position(position), AList(Alist), timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(5), onGround(false), onPlataform(0)
{
	direction = Vector2();
}

Entity::Entity(Vector2& position, AnimationList& Alist, float& speed) : position(position), AList(Alist), timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(speed), onGround(false), onPlataform(0)
{
	direction = Vector2();
}

Entity::Entity(AnimationList& Alist) : AList(AList), timer(0), frame(0), gravity(800), horizontalSpeed(250), speed(5), onGround(false), onPlataform(0)
{
	position = Vector2();
	direction = Vector2();
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
	position.y += speed * GetFrameTime();
	speed += gravity * GetFrameTime();
	//setOnground(false);
}

void Entity::moveEntity()
{
	position.x += horizontalSpeed * direction.x * GetFrameTime();
}

void Entity::animateEntity()
{
	int walk = 0;
	int idle = 1;
	int jump = 2;
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
	animateEntity();
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

void Entity::setList(AnimationList& nList)
{
	AList = nList;
}

void Entity::setPosition(Vector2& position)
{
	this->position = position;
}
