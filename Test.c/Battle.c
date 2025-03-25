#if 0
#include "Battle.h"

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

		setCursorPos(monster.x, monster.y);
		printf("%s", monster.action1);

		player.health -= monster.attack;

		if (player.health < 0)
		{
			player.health = 0;
		}
		monster.health -= player.attack;
		if (monster.health < 0)
		{
			monster.health = 0;
		}
	}
	else
	{
		setCursorPos(player.x, player.y);
		printf("%s", player.acthion2);

		setCursorPos(monster.x, monster.y);
		printf("%s", monster.acthion2);
	}
	ShowAttack++;
	Sleep(500);
}
#endif // 0
