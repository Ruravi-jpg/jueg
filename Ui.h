#pragma once

#include <iostream>
#include <string>

#include "raylib.h"
#include "LevelLoader.h"

class Ui
{
public:
	static Ui& get();

	void drawPlayerData();

private:
	Ui();

	void IdrawPlayerData();
};

