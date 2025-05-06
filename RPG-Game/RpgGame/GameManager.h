#pragma once

#include "Player.h"
#include "Enemy.h"


class GameManager
{
public:
	Player Sword;
	Player Arrow;
	Enemy Slime;

public:
	GameManager() :
	 Sword(5, 10, 11, 100, "바바리안", SwordIdle),
	 Arrow(5, 10, 11, 100, "아마존", ArrowIdle),
	 Slime(40, 10, 6, 50, "슬라임", SlimeIdle) { }



	void GameStart()
	{
		while (true)
		{
			Arrow.ShowImage();
			Slime.SetBattle(SlimeIdle);
			Sleep(300);
			Slime.SetBattle(SlimeMove);
			Sleep(300);

			//Slime.Battle(&Arrow, Slime);
		}


	}
};



