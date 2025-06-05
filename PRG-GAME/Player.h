#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player(int posX, int posY, int attack, int hp, string name, const char* model)
		: Character(posX, posY, attack, hp, name, model) { }

	void ShowImage()
	{
		for (size_t i = 0;i < IMAGE.size();i++)
		{
			Console::GoToXY(X, Y + static_cast<int>(i));     
			cout << IMAGE[i] << endl;
		}
	}
};

