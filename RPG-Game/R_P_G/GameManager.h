#pragma once

#include "Player.h"
#include "Enemy.h"

Player Sword = { 10,10,11,1000,"�ٹٸ���",SwordIdle };
Player Arrow = { 10,10,11,100,"�Ƹ���",ArrowIdle };
Enemy Slime = { 35,10,6,50,"������",SlimeIdle };
Enemy KingSlime = { 35,10,60,500,"ŷ������",KingSlimeIdle };


//void GameCharacterSelect()
//{
//
//}


void GameStart()
{
	Random();

	while (true)
	{
		Slime.ShowGold();


		GoToXY(0, 15);
		cout << "=================================================";



		Sword.ShowImage();
		Slime.Move(Sword);
	}
}




