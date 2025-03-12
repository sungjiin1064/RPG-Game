#include "battle.h"

void inBattle()
{
	static int attacking = 1;

	if (attacking % 2 != 0)
	{
		setCursorPos(playerX, playerY);
		printf("(  '' )/");
		setCursorPos(monsterX, monsterY);
		printf(" ( ''  )");
		playerHealth -= monsterAttack;
		if (playerHealth < 0)
		{
			playerHealth = 0;
		}
		monsterHealth -= playerAttack;
		if (monsterHealth < 0)
		{
			monsterHealth = 0;
		}


	}
	else
	{

		setCursorPos(playerX, playerY);
		printf("(  '' )¤ÑE");
		setCursorPos(monsterX, monsterY);
		printf("( ''   )");
	}
	attacking++;
}