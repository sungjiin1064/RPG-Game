#pragma once

#include "Character.h"

class Monster : public Character
{
public:
	Monster(int posX, int posY, int attack, int hp, string name, const char* model)
		: Character(posX, posY, attack, hp, name, model) { }

	void ShowImage()
	{
		for (size_t i = 0;i < IMAGE.size();i++)
		{
			Console::GoToXY(X, Y + static_cast<int>(i));
			cout << IMAGE[i] << endl;
		}
	}

	void ChangeImage(ImageModel& model)
	{
		if (model.isIdle)
		{
			model.CurrentImage = model.SlimeMove;
			model.isIdle = false;
		}
		else
		{
			model.CurrentImage = model.SlimeIdle;
			model.isIdle = true;
		}
			
	
	}

	void Move(ImageModel& model)
	{		
		if (X > 20)
		{			
			ChangeImage(model);
			X--;
			Sleep(100);
		}
		else
		{
			return;
		}
	}
};

