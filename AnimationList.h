#pragma once

#include <list>
#include <vector>
#include <iterator>
#include "raylib.h"



class AnimationSt {
private:
	Texture2D texture;
	int cols;
	int rows;
	int speed;

	float frameWidth;
	int maxFrames;


public:
	AnimationSt(const AnimationSt& copy);
	AnimationSt(Texture2D& texture, int cols, int rows, int speed);

	void animate(Vector2& position, float&timer, int& frame);

	Texture2D getTexture()const;

	int getCols()const;
	int getRows()const;

	void unloadText();

	int getWidthFrame()const;

};

class AnimationList
{

private:

	std::vector<AnimationSt> animationList;

public:
	AnimationList();
	AnimationList(std::vector<AnimationSt>& animationList);

	std::vector<AnimationSt> getList();

	AnimationSt getAnimation(int index)const;

	void unloadText();

};

