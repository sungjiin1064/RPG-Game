
#include "Move.h"
#include "Stage.h"

void MoveSlime(Character* slime, Character* player)
{
	while (slime->x > player->x + 12)
	{
		system("cls");

		ShowStage(Stage, 0, 0);
		ShowGold(&inventory);

		PlayerAction(player, 1);
		SlimeAction(slime, 1); // �⺻ ���� ���
		slime->x--; // X ��ǥ ����
		Sleep(70);
	}
}

void MoveBoss(BossCharacter* boss, Character* player)
{
	while (boss->x > player->x + 12)
	{
		system("cls");

		ShowStage(Stage, 0, 0);
		ShowGold(&inventory);

		GoToXY(2, 4);
		printf("���� ���Ͱ� ��ȯ�Ǿ����ϴ�.");

		PlayerAction(player, 1);
		BossAction(boss, 1); // �⺻ ���� ���
		boss->x--; // X ��ǥ ����
		Sleep(100);
	}
}