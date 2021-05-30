#pragma once

#include "AnimationList.h"



AnimationList::AnimationList()
{
	animationList = std::vector<AnimationSt>();
}

AnimationList::AnimationList(std::vector<AnimationSt>& animationList)
{
	this->animationList.operator=(animationList);

}

std::vector<AnimationSt> AnimationList::getList()
{
	return animationList;
}

AnimationSt AnimationList::getAnimation(int index)const
{
	return this->animationList[index];
}

void AnimationList::unloadText()
{
	for (AnimationSt i : animationList) {
		i.unloadText();
	}
}



AnimationSt::AnimationSt(const AnimationSt& copy)
{
	this->texture = copy.texture;
	this->cols = copy.cols;
	this->rows = copy.rows;
	this->speed = copy.speed;
	this->frameWidth = copy.frameWidth;
	this->maxFrames = copy.maxFrames;

}

AnimationSt::AnimationSt(Texture2D& texture, int cols, int rows, int speed) :texture(texture), cols(cols), rows(rows), speed(speed), frameWidth(0), maxFrames(0)
{
}

void AnimationSt::animate(Vector2& position, float& timer, int& frame)
{
	float frameWidth = (float)(texture.width / cols);
	int maxFrames = (int)(texture.width) / (int)frameWidth;
	timer += GetFrameTime();

	if (timer >= 60/speed * GetFrameTime()) {
		timer = 0.0f;
		frame += 1;
	}

	frame = frame % maxFrames;

	DrawTextureRec(texture,
		Rectangle{
			(frameWidth * frame),
			0,
			frameWidth,
			(float)texture.height },
			position,
			RAYWHITE);
}

Texture2D AnimationSt::getTexture() const
{
	return texture;
}

int AnimationSt::getCols() const
{
	return cols;
}

void AnimationSt::unloadText()
{
	UnloadTexture(texture);
}

int AnimationSt::getWidthFrame() const
{
	float frameWidth = (float)(texture.width / cols);

	return frameWidth;
}
