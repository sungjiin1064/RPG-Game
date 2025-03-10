#include <stdio.h>
#include <Windows.h>
#include "outline.h"

void setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int playerX = 10;
int playerY = 10;
int monsterX = 60;
int monsterY = 10;


int playerHealth = 100;
int monsterHealth = 50;
int playerAttack = 9;
int monsterAttack = 6;

void monsterDie(int x, int y)
{
		setCursorPos(playerX + 3, playerY - 5);
		printf("슬라임을 처치하였습니다.\n");
		setCursorPos(x, y);
		printf("           ");
		setCursorPos(x + 2, y - 2);
		//printf("                       ");
		setCursorPos(x + 3, y);
		printf("(x . x)");
		//setCursorPos(monsterX + 2, monsterY - 2);
		//printf("- 사  망 -");
	
}

void resetMonster()
{
	monsterX = 60;
	monsterY = 10;
	monsterHealth = 50;
}

int main()
{
	GameStart();

	while (1)
	{
		

		system("cls");
		line();

		setCursorPos(playerX - 4, playerY - 2);
		printf("기사 체력: %d", playerHealth);
		setCursorPos(monsterX + 2, monsterY - 2);
		printf("슬라임 체력 : %d", monsterHealth);
		setCursorPos(monsterX, monsterY);
		printf("ㅡ０( ''  )");
		setCursorPos(playerX, playerY);
		printf("(  '' )ㅡE");

		if (monsterX > playerX + 13)
		{
			monsterX--;
			Sleep(100);
		}
		else
		{
			setCursorPos(playerX + 8, playerY - 5);
			printf("전투중...");
			setCursorPos(playerX + 11, playerY - 1 );
			printf("VS");

			playerHealth -= monsterAttack;

			monsterHealth -= playerAttack;
			if (monsterHealth < 0)
			{
				monsterHealth = 0;
			
			}



			if (monsterHealth <= 0)
			{
				

				monsterDie(monsterX, monsterY);
				Sleep(10000);
				resetMonster();

			}

			if (playerHealth <= 0)
			{
				GameOver();
				break;
			}

			Sleep(500);
		}

	}
}