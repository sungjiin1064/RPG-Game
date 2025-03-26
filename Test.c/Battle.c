#include "Battle.h"
#include "Character.h"



void ShowBattle()
{

	setCursorPos(player.x + 7, player.y - 5);
	printf("РќХѕСп...");
	setCursorPos(player.x + 11, player.y);
	printf("vs");

	static int ShowAttack = true;

	if (ShowAttack % 2 != false)
	{
		setCursorPos(player.x, player.y);
		printf("%s", player.action1);

		setCursorPos(slime.x, slime.y);
		printf("%s", slime.action1);

		player.health -= slime.attack;

		if (player.health < 0)
		{
			player.health = 0;
			
		}
		slime.health -= player.attack;
		if (slime.health < 0)
		{
			slime.health = 0;
			
		}
	}
	else
	{
		setCursorPos(player.x, player.y);
		printf("%s", player.action2);

		setCursorPos(slime.x, slime.y);
		printf("%s", slime.action2);
	}
	ShowAttack++;
	Sleep(500);

}

