
#include "Battle.h"


// ������Ͽ� �ű�ϱ� ������ ���� ���ο� ���ֽ��ϴ�. 
// ShowBattle�� ����� �ű�� ������ �ҽ����Ͽ� �ű�� player�� monster�� Battle.obj�� �̹� ���ǵǾ� �ֽ��ϴ�.��� �߳׿�
//                                                

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

Character player = { 10,10,50,11,"(  '' )/","(  '' )��E" };
Character monster = { 60,10,30,6," ( ''  )","( ''   )" };



void startPosition()
{
	setCursorPos(player.x - 8, player.y - 2);
	printf("�÷��̾� ü�� : %d", player.health);
	setCursorPos(player.x, player.y);
	printf("%s", player.action1);
	setCursorPos(monster.x, monster.y - 2);
	printf("������ ü�� : %d", monster.health);
	setCursorPos(monster.x, monster.y);
	printf("%s", monster.action1);
}


void ShowBattle()
{

	setCursorPos(player.x + 7, player.y - 5);
	printf("������...");
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
		setCursorPos(player.x, player.y);    // ���ݸ���϶� �ǰ��ް�
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
				startPosition();  // �ǰ� 0 �ǰ��Ŀ� �����ǰ��ҷ��� �ߴµ� ��Ÿ����� ���� 0�̵˴ϴ�.

				Sleep(1000);
				respawn(); //�������� ���Ͱ� �ٰ��ͼ� ������ �����ϸ� ���1���� �ȵǰ� ���2���� ���۵˴ϴ�.
			}

			if (player.health <= 0)
			{
				startPosition(); // �ǰ� 0�̵��� ���. ���� ��Ǿ��� 0�̵˴ϴ�
				Sleep(1000);
				break;
			}

		}
		Sleep(50);
	}
	return;
}