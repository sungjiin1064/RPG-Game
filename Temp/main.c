

#include "Character.h"
#include "Stage.h"

typedef struct
{
	int x, y, attack, health;
	char name[20];
	char action1[SLIME_WIDTH + 1];
	char action2[SLIME_WIDTH + 1];
	char action3[SLIME_WIDTH + 1];
}Character;

typedef struct
{
	int x, y, attack, health;
	char name[20];
	char action1[SLIME_HEIGHT][SLIME_WIDTH + 1]; // �⺻ ���� (3��)
	char action2[SLIME_HEIGHT][SLIME_WIDTH + 1]; // ���� ���� (3��)
	char action3[SLIME_HEIGHT][SLIME_WIDTH + 1]; // ��� ���� (3��)
}KingCharacter;

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

void KingslimeMoving(KingCharacter* kingSlime)
{
	GoToXY(kingSlime->x - 30, kingSlime->y);
	printf("..o");
	GoToXY(kingSlime->x - 2, kingSlime->y - 8);
	printf("��");
	GoToXY(kingSlime->x - 10, kingSlime->y - 9);
	printf("�ڡ�    ��     ��    �� ��");
	GoToXY(kingSlime->x - 2, kingSlime->y - 10);
	printf("��      ��    ��  ");
	kingSlime->x--;
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

void BattleWithKingSlime(Character* player, KingCharacter* kingSlime, char (*Slime)[SLIME_WIDTH + 1])
{

	static int ShowAttack = true;

	if (ShowAttack % 2 != false)
	{
		GoToXY(player->x, player->y);
		printf("%s", player->action1);


		KingSlime(SlimeWALK, kingSlime->x, kingSlime->y);

		player->health -= kingSlime->attack;
		if (player->health < 0)
		{
			player->health = 0;
		}
		kingSlime->health -= player->attack;
		if (kingSlime->health < 0)
		{
			kingSlime->health = 0;
		}
	}
	else
	{
		GoToXY(player->x, player->y);
		printf("%s", player->action2);

		KingSlime(SlimeFIGHT, kingSlime->x, kingSlime->y);
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

void KingSlimeRespawn(KingCharacter* kingSlime)
{
	GoToXY(kingSlime->x, kingSlime->y);
	printf("%s", kingSlime->action1);
	kingSlime->health;
	
}

//                   x   y ��  ��  �̸�    �׼�1(�⺻)  �׼�2(����)  �׼�3(���)
Character player = { 25,10,11,100,"����",  "(  '' )/","(  '' )��E","__+__" };
Character slime = { 52,10, 4, 20,"������"," ( ''  )","( ''   )"," ( x x )" };
KingCharacter kingSlime = { 52,10, 11, 200,"ŷ������"," - -"," - ..  -","_ _ _ _ _ _", " - -","- ..  -","_ _ _ _ _ _", " - - - - -","'_ _x x_ _'" };

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
			/*SlimeMove(SlimeWALK, slime.x, 8);
			slime.x--;
			Sleep(50);*/
			slimeMoving(&slime);

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

					

					kingSlimeSpawn = 1;
					KingSlimeRespawn(&kingSlime);
					KingSlime(SlimeWALK, slime.x, 8);	// ������ ��ȯ
					//slime.x--;
					Sleep(100);

					if (slime.x > player.x + 11)
					{
						
						KingslimeMoving(&kingSlime);
						
						Sleep(1000);
						//GoToXY(slime.x, slime.y - 3);  // ���������� �ܻ�����
						//printf("              ");
						//GoToXY(slime.x, slime.y - 2);  // ���������� �ܻ�����
						//printf("                         ");
						//GoToXY(slime.x, slime.y);
						//printf("               ");

						//KingSlime(SlimeWALK, slime.x - 1, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 2, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 3, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 4, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 5, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 6, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 7, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 8, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 9, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 10, 8);
						//Sleep(50);
						//KingSlime(SlimeWALK, slime.x - 11, 8);
						//Sleep(50);
					

					}
					else
					{
						BattleWithKingSlime(&player, &slime, SlimeWALK);
					}





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