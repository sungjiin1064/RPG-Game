
#include "Battle.h"
                                              

void setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


typedef struct
{
	int x, y, health, attack;
	char action1[20];
	char acthion2[20];

}Character;

Character player = { 10,10,50,11,"(  '' )/","(  '' )ㅡE" };
Character monster = { 60,10,30,6," ( ''  )","( ''   )" };



void startPosition()
{
	setCursorPos(player.x - 8, player.y - 2);
	printf("플레이어 체력 : %d", player.health);
	setCursorPos(player.x, player.y);
	printf("%s", player.action1);
	setCursorPos(monster.x, monster.y - 2);
	printf("슬라임 체력 : %d", monster.health);
	setCursorPos(monster.x, monster.y);
	printf("%s", monster.action1);
}


void ShowBattle()
{

	setCursorPos(player.x + 7, player.y - 5);
	printf("전투중...");
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

		if (player.health < 0)              //  왜 여기에다 입력해야 action2가 보여질때 피가 달죠? 
		{                                   // action2 동작때 피가다는거니깐 밑에 쓰는거 아닌가요?
			player.health = 0;              // 여기에 쓰는게 맞나요?
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



void respawn()
{
	monster.x = 60;
	monster.health = 50;
}

int main()
{
	while (true)
	{
		system("cls");

		startPosition();


		if (monster.x > player.x + 14)
		{
			monster.x--;
			Sleep(10);
		}
		else
		{
			ShowBattle();

			if (monster.health <= 0)
			{
				
				//startPosition();  // 피가 0 되고난후에 리젠되게할려고 했는데 막타모션이 없이 0이됩니다.
				//Sleep(1000);

				respawn(); //리스폰된 몬스터가 다가와서 전투를 시작하면 모션1부터 안되고 모션2부터 시작됩니다.
			}

			if (player.health <= 0)
			{
				//startPosition(); // 피가 0이된후 사망. 역시 모션없이 0이됩니다
				//Sleep(1000);
				break;
			}

		}
		Sleep(50);
	}
	return;
}