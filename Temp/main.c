

#include "Character.h"
#include "Stage.h"

typedef struct
{
	int x, y, attack, health;
	char name[20];
	char action1[20];
	char action2[20];
	char action3[20];
}Character;

void StartPosition(Character* player, Character* slime)
{
	GoToXY(player->x - 1, player->y - 2);
	printf("%s : %d", player->name, player->health);
	GoToXY(player->x, player->y);
	printf("%s", player->action1);
	GoToXY(slime->x, slime->y - 2);
	printf("%s : %d", slime->name, slime->health);
	GoToXY(slime->x, slime->y);
	printf("%s", slime->action1);
}

void slimeMoving(Character* slime)
{
	GoToXY(slime->x - 30, slime->y);
	printf("..o");
	GoToXY(slime->x - 2, slime->y - 8);
	printf("��");
	GoToXY(slime->x - 10, slime->y - 9);
	printf("�ڡ�    ��     ��    �� ��");
	GoToXY(slime->x - 2, slime->y - 10);
	printf("��      ��    ��  ");
	slime->x--;
	Sleep(50);
}

void BattleWithslime(Character* player, Character* slime)
{
	GoToXY(slime->x - 2, slime->y - 8);
	printf("��                    ��");
	GoToXY(slime->x - 10, slime->y - 9);
	printf("�ڡ�    ��     ��    �� ��");
	GoToXY(slime->x - 2, slime->y - 10);
	printf("��      ��    ��  ");
	GoToXY(player->x + 7, player->y - 5);
	printf("������...");
	GoToXY(player->x + 11, player->y);
	printf("vs");

	static int ShowAttack = true;

	if (ShowAttack % 2 != false)
	{
		GoToXY(player->x, player->y);
		printf("%s", player->action1);

		GoToXY(slime->x, slime->y);
		printf("%s", slime->action1);

		player->health -= slime->attack;
		if (player->health < 0)
		{
			player->health = 0;
		}
		slime->health -= player->attack;
		if (slime->health < 0)
		{
			slime->health = 0;
		}
	}
	else
	{
		GoToXY(player->x, player->y);
		printf("%s", player->action2);

		GoToXY(slime->x, slime->y);
		printf("%s", slime->action2);
	}
	ShowAttack++;
	Sleep(500);
}

void BattleWithKingSlime(Character* player, Character* slime, char (*Slime)[SLIME_WIDTH + 1])
{	

	static int ShowAttack = true;

	if (ShowAttack % 2 != false)
	{
		GoToXY(player->x, player->y);
		printf("%s", player->action1);

		
		SlimeMove(SlimeWALK, slime->x, slime->y - 2);

		player->health -= slime->attack;
		if (player->health < 0)
		{
			player->health = 0;
		}
		slime->health -= player->attack;
		if (slime->health < 0)
		{
			slime->health = 0;
		}
	}
	else
	{
		GoToXY(player->x, player->y);
		printf("%s", player->action2);

		SlimeMove(SlimeFIGHT, slime->x, slime->y - 2);
	}
	ShowAttack++;
	Sleep(500);
}

int slimeCount = 0;
int kingSlimeSpawn = 0;

void checkSlimeCount(Character* slime, Character* player)
{

	if (slime->health <= 0)
	{
		slimeCount++;
		GoToXY(player->x - 10, player->y - 7);
		printf("%d / 3", slimeCount);
	}
}

void SlimeRespawn(Character* slime)
{
	slime->health = 20;
	slime->x = 52;
}

//                   x   y ��  ��  �̸�    �׼�1(�⺻)  �׼�2(����)  �׼�3(���)
Character player = { 25,10,11,100,"����",  "(  '' )/","(  '' )��E","__+__" };
Character slime = { 52,10, 4, 20,"������"," ( ''  )","( ''   )"," ( x x )" };

int main()
{
	ShowStage(Stage, 0, 0);

	//GameStart();

	while (1)
	{
		system("cls");

		ShowStage(Stage, 0, 0);

		StartPosition(&player, &slime);

		//int slimeX = 40;

		if (slime.x > player.x + 14)
		{
			SlimeMove(SlimeWALK, 52, 8);
			slime--;
			//slimeMoving(&slime);

		}
		else
		{
			BattleWithslime(&player, &slime);

			if (slime.health <= 0)                 // ���ڵ带 battle�ȿ� ������ ����?
			{
				StartPosition(&player, &slime);     // ��Ÿ�� �׼� 2���۶� �ǰ� 0���̰��ҷ���
				BattleWithslime(&player, &slime);   // ��Ÿ����� ���� �������Ͱ� �ٰ������� ���2 ���� ����

				GoToXY(player.x, player.y);  // ���� �ܻ� ���ֱ�
				printf("          ");
				GoToXY(player.x, player.y - 2);  // ���Ͱ� �ѹ��� ���� 100���� �ڿ� 0 �ܻ��̳���
				printf("         ");
				GoToXY(slime.x, slime.y - 2);  // ���Ͱ� �ѹ��� ���� ü���� 00�� ������ �ڿ�0�� �ܻ��ΰ� ����
				printf("             ");

				StartPosition(&player, &slime);     // �ܻ���ذ� �����ֱ����ؼ�	

				GoToXY(slime.x, slime.y);
				printf("%s", slime.action3);

				checkSlimeCount(&slime, &player);

				Sleep(1000);

				if (player.health > 0 && slimeCount < 1)
				{
				
					SlimeRespawn(&slime);
				}
				else if (slimeCount == 1 && kingSlimeSpawn == 0)
				{
					GoToXY(slime.x, slime.y - 2);  // ���������� �ܻ�����
					printf("           ");
					GoToXY(slime.x, slime.y);
					printf("         ");

					SlimeRespawn(&slime);
					
					kingSlimeSpawn = 1;
					SlimeMove(SlimeWALK, slime.x, slime.y -2);	// ������ ��ȯ
					
					if (slime.x > player.x + 1)
					{
						SlimeMove(SlimeWALK, slime.x, slime.y - 2);
						slime.x--;
						Sleep(50);
					}
					else
					{
						BattleWithKingSlime(&player, &slime, SlimeWALK);
					}

					//SlimeMove(SlimeWALK, slime.x-1, slime.y -2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x-2, slime.y -2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x-3, slime.y -2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 4, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 5, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 6, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 7, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 8, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 9, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 10, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 11, slime.y - 2);
					//Sleep(50);
					//SlimeMove(SlimeWALK, slime.x - 12, slime.y - 2);
					//Sleep(50);

					

					Sleep(1000);
				}
				else
				{

				}
			}

			if (player.health <= 0)
			{
				StartPosition(&player, &slime);    
				BattleWithslime(&player, &slime);  
				StartPosition(&player, &slime);

				GoToXY(player.x, player.y);  
				printf("          ");
				GoToXY(player.x, player.y - 2); 
				printf("         ");
				GoToXY(slime.x, slime.y - 2);  
				printf("             ");
				
				GoToXY(player.x, player.y);
				printf("%s", player.action3);

				Sleep(1000);
				break;

			}

		}

	}
	return;

}