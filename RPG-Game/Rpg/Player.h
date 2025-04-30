#pragma once

#include "Common.h"
#include "Image.h"
#include "Character.h"

class Player : public Character
{
public:

	Player(int posX, int posY, int attack, int hp, string name, char Image[UNIT_HEIGHT][UNIT_WIDTH + 1]) :
		Character(posX, posY, attack, hp, name, Image) { }
	
	void ChangeImage()
	{
		for (int y = 0; y < UNIT_HEIGHT; y++)
		{
			for (int x = 0; x < UNIT_WIDTH;x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}
	}

	void ShowImage(char Image[UNIT_HEIGHT][UNIT_WIDTH + 1])
	{
		for (int y = 0; y < UNIT_HEIGHT;y++)
		{
			for (int x = 0; x < UNIT_WIDTH; x++)
			{
				GoToXY(posX + x, posY + y);
				cout << Image[y][x];
			}
			cout << endl;
		}

	}
};

