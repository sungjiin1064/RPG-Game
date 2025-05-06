#pragma once

#include "Common.h"
#include "Image.h"

class Character
{
public:
	int X;
	int Y;
	int ATK;
	int HP;
	string name;
	char Image[UNIT_HEIGHT][UNIT_WIDTH + 1];

	Character(int posX, int posY, int attack, int hp, string name, char Image[UNIT_HEIGHT][UNIT_WIDTH + 1]) :
		X(posX), Y(posY), ATK(attack), HP(hp), name(name)
	{
		for (int y = 0;y < UNIT_HEIGHT;y++)
		{
			for (int x = 0;x < UNIT_WIDTH+1;x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}

	}

	

};

