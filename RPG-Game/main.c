#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include "outline.h"
#include "battle.h"
#include "respawn.h"
#include "win_loss.h"

void setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int playerX = 10;
int playerY = 10;
int monsterX = 60;
int monsterY = 10;

int playerHealth = 300;
int monsterHealth = 50;
int playerAttack = 11;
int monsterAttack = 6;

int main()
{
	GameStart();

	while (1)
	{
		system("cls");
		line();

		setCursorPos(playerX - 4, playerY - 2);
		printf("기사 체력: %d", playerHealth);
		setCursorPos(monsterX, monsterY - 2);
		printf("슬라임 체력 : %d", monsterHealth);
		setCursorPos(monsterX, monsterY);
		printf("( ''  )");
		setCursorPos(playerX, playerY);
		printf("(  '' )/");

		if (monsterX > playerX + 14)
		{
			monsterX--;
			Sleep(50);
		}
		else
		{
			setCursorPos(playerX + 8, playerY - 5);
			printf("전투중...");
			setCursorPos(playerX + 11, playerY - 1);
			printf("VS");

			inBattle();

			if (monsterHealth <= 0)
			{
				monsterDie(monsterX, monsterY);
				playerWin(playerX, playerY);
				Sleep(2000);
				respawnSlime();
			}

			if (playerHealth <= 0)
			{
				playerDie(playerX, playerY);
				monsterWin(monsterX, monsterY);
				Sleep(5000);
				GameOver();
				break;
			}
			Sleep(500);
		}
	}
}