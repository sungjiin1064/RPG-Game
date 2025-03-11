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

int playerHealth = 300;
int monsterHealth = 50;
int playerAttack = 9;
int monsterAttack = 6;

void monsterWin(int x, int y)
{
	setCursorPos(x, y);
	printf("             ");
	setCursorPos(x, y);
	printf("v( ^.^ )");
}

void monsterDie(int x, int y)
{
	setCursorPos(monsterX, monsterY - 2);
	printf("������ ü�� : %d", monsterHealth);
	setCursorPos(playerX - 4, playerY - 2);
	printf("��� ü��: %d", playerHealth);
	setCursorPos(playerX + 3, playerY - 5);
	printf("�������� óġ�Ͽ����ϴ�.\n");
	setCursorPos(x, y);
	printf("               ");  
	setCursorPos(x , y);
	printf(" (x . x)");
}

void playerWin(int x, int y)
{
	setCursorPos(x, y);
	printf("             ");
	setCursorPos(x, y);
	printf("( ^.^ )v");
}

void playerDie(int x, int y)
{
	setCursorPos(playerX + 3, playerY - 5);
	printf("�ɸ��Ͱ� ����Ͽ����ϴ�...");
	setCursorPos(playerX - 4, playerY - 2);
	printf("��� ü��: %d", playerHealth);
	setCursorPos(monsterX, monsterY - 2);
	printf("������ ü�� : %d", monsterHealth);
	setCursorPos(x, y);
	printf("             ");
	setCursorPos(x, y);
	printf("(x . x)");
}

void attacking()
{
	static int attacking = 0;
	
	if (attacking % 2 == 0)
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
		printf("(  '' )��E");
		setCursorPos(monsterX, monsterY);
		printf("( ''   )");
	}
	attacking++;
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
		printf("��� ü��: %d", playerHealth);
		setCursorPos(monsterX , monsterY - 2);
		printf("������ ü�� : %d", monsterHealth);
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
			printf("������...");
			setCursorPos(playerX + 11, playerY - 1 );
			printf("VS");

			attacking();
					
			if (monsterHealth <= 0)
			{
				monsterDie(monsterX, monsterY);
				playerWin(playerX, playerY);
				Sleep(2000);
				resetMonster();
			}

			if (playerHealth <= 0)
			{
				playerDie(playerX, playerY);
				monsterWin(monsterX, monsterY);
				Sleep(3000);
				GameOver();
				break;
			}

			Sleep(500);
		}

	}
}