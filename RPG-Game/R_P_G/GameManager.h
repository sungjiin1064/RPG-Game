#pragma once

#include "Player.h"
#include "Enemy.h"

Player Sword = { 10,10,11,1000,"바바리안",SwordIdle };
Player Arrow = { 10,10,11,100,"아마존",ArrowIdle };
Enemy Slime = { 35,10,6,50,"슬라임",SlimeIdle };
Enemy KingSlime = { 35,10,60,500,"킹슬라임",KingSlimeIdle };


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




