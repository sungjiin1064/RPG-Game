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
int monsterX = 30;
int monsterY = 10;

int playerHealth = 100;
int monsterHealth = 50;
int playerAttack = 9;
int monsterAttack = 4;

void resetMonster()
{
	monsterX = 30;
	monsterY = 10;
	monsterHealth = 50;
}

int main()
{

	while (1)
	{
		system("cls");
		line();

		setCursorPos(playerX - 4, playerY - 2);
		printf("기사 체력: %d", playerHealth);
		setCursorPos(monsterX + 2, monsterY - 2);
		printf("슬라임 체력 : %d", monsterHealth);
		setCursorPos(monsterX, monsterY);
		printf("====( ''  )");
		setCursorPos(playerX, playerY);
		printf("(  '' )ㅡㅡ");

		if (monsterX > playerX + 10)
		{
			monsterX--;
			Sleep(50);
		}
		else
		{
			setCursorPos(playerX + 8, playerY - 5);
			printf("전투중...");

			monsterHealth -= playerAttack;
			playerHealth -= monsterAttack;



			if (monsterHealth <= 0)
			{
				setCursorPos(playerX + 8, playerY - 5);
				printf("슬라임을 처치하였습니다.");
				resetMonster();

			}

			if (playerHealth <= 0)
			{
				setCursorPos(playerX + 6, playerY - 5);
				printf("사망하였습니다.");
				setCursorPos(playerX + 8, playerY + 2);
				printf("게임 종료\n");
				break;
			}

			Sleep(200);
		}

	}
}