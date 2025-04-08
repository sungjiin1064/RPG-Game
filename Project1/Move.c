
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
		SlimeAction(slime, 1); // 기본 상태 출력
		slime->x--; // X 좌표 감소
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
		printf("보스 몬스터가 소환되었습니다.");

		PlayerAction(player, 1);
		BossAction(boss, 1); // 기본 상태 출력
		boss->x--; // X 좌표 감소
		Sleep(100);
	}
}