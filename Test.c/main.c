
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
				startPosition();                   // �ǰ� 0���� �����ְ� ���

				ShowBattle();                      // ��Ÿ����� ���� �������Ͱ� �ٰ������� ���2 ���� ����

				setCursorPos(player.x, player.y);  // ���� �ܻ� ���ֱ�
				printf("          ");
				setCursorPos(player.x, player.y);  // ���Ͱ� �װ� �⺻������� ������. ���2�� �����ϱ� �̻��ؼ�
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