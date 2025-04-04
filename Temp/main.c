
#include <stdio.h>   
#include <stdbool.h>
#include <Windows.h>


typedef struct
{
	int x, y, attack, health;
	char name[20];
	char action1[20];
	char action2[20];
	char action3[20];
}Character;

void GoToXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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
	slime->x--;
	Sleep(50);
}

void BattleWithslime(Character* player, Character* slime)
{
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

void SlimeRespawn(Character* slime)
{
	slime->health = 30;
	slime->x = 40;
}

//                   x   y  �� ��  �̸�  �׼�1(�⺻)  �׼�2(����)  �׼�3(���)
Character player = { 10,10,11,100,"����","(  '' )/","(  '' )��E","__+__" };
Character slime = { 40,10,4,20,"������"," ( ''  )","( ''   )"," ( x x )" };

int main()
{
	while (1)
	{
		system("cls");

		StartPosition(&player, &slime);

		if (slime.x > player.x + 14)
		{
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
				GoToXY(player.x, player.y-2);  // ���Ͱ� �ѹ��� ���� 100���� �ڿ� 0 �ܻ��̳���
				printf("         ");
				GoToXY(slime.x, slime.y -2);  // ���Ͱ� �ѹ��� ���� ü���� 00�� ������ �ڿ�0�� �ܻ��ΰ� ����
				printf("           ");

				StartPosition(&player, &slime);     // �ܻ���ذ� �����ֱ����ؼ�	

				GoToXY(slime.x, slime.y);
				printf("%s", slime.action3);				
				
				Sleep(1000);

				SlimeRespawn(&slime);

			}

		}

	}
	return;

}