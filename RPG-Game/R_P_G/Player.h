#pragma once

#include "Character.h"

//enum PlayerType
//{
//	Arhcor,
//	Sword
//};
//
//enum PlayerAction
//{
//	Idle,
//	Battle,
//	Die,
//	Move
//};

class Player : public Character
{

public:
	Player(int posX,int posY,int attack,int hp,string name, char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
		: Character(posX,posY,attack,hp,name,image) { }

public:
	void ShowImage();
	
	/*void GetImageByType(PlayerType type) {
		switch (type)
		{

		}
	}
	
	void GetImage(PlayerType type, PlayerAction action)
	{

	}*/

};

