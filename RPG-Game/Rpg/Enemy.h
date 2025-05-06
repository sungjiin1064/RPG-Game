#pragma once



#include "Character.h"

class Enemy : public Character
{
public:

	Enemy(int posX, int posY, int attack, int hp, string name, char Image[UNIT_HEIGHT][UNIT_WIDTH + 1]) :
		Character(posX, posY, attack, hp, name, Image) {
	}

	void ChangeImage()
	{
		for (int y = 0; y < UNIT_HEIGHT; y++)
		{
			for (int x = 0; x < UNIT_WIDTH+1;x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}
	}

	void ShowImage();

};

