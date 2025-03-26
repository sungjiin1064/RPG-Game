
#include "Battle.h"
#include "Character.h"   

int slimeCount = 0;
//int kingSlimeSpawn = 0;
void checkSlimeCount()
{
	if (slime.health <= 0)
	{
		slimeCount++;
		setCursorPos(player.x + 7, player.y - 3);
		printf("%d / 3", slimeCount);
		if (slimeCount >= 3)
		{
			KingRespawn();
			//kingSlimeSpawn = 1;
		}
		respawn();
	}
}

int main()
{
	while (true)
	{
		system("cls");

		startPosition();

		if (slime.x > player.x + 14)
		{
			slime.x--;
			Sleep(10);
		}
		else
		{
			ShowBattle();

			if (slime.health <= 0)
			{
				startPosition();                   // 피가 0으로 보여주고 사망

				ShowBattle();                      // 막타모션이 없고 리젠몬스터가 다가왔을때 모션2 부터 시작

				setCursorPos(player.x, player.y);  // 무기 잔상 없애기
				printf("          ");
				setCursorPos(player.x, player.y);  // 몬스터가 죽고 기본모션으로 돌리기. 모션2로 끝나니깐 이상해서
				printf("%s", player.action1);
				setCursorPos(slime.x, slime.y);
				printf("%s", slime.action3);
				checkSlimeCount();
				Sleep(1000);

				respawn();
			}
			

			if (player.health <= 0)
			{
				startPosition();
				ShowBattle();
				setCursorPos(slime.x, slime.y);
				printf("            ");
				setCursorPos(slime.x, slime.y);
				printf("%s", slime.action1);
				setCursorPos(player.x, player.y);
				printf("             ");
				setCursorPos(player.x, player.y);
				printf("%s", player.action3);
			
			
				Sleep(1000);
				break;
			}

		}
		Sleep(50);
	}
	return;
}