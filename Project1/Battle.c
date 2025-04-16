
#include "Battle.h"
#include "Stage.h"

void BattleWithSlime(Character* player, Character* slime, int slimeCount)
{
	ShowStage(Stage, 0, 0);
	ShowGold(&inventory);

	GoToXY(2, 4);
	printf("보스 몬스터 소환 %d / 5", slimeCount);

	static int ShowAttack = true;

	if (ShowAttack % 2 != false)
	{
		PlayerAction(player, 1);
		SlimeAction(slime, 1);
	}
	else
	{
		player->health -= slime->attack;
		slime->health -= player->attack;

		SlimeAction(slime, 2);
		PlayerAction(player, 2);
		if (player->health <= 0)
		{
			system("cls");                // 막타

			ShowStage(Stage, 0, 0);
			ShowGold(&inventory);

			player->health = 0;
			PlayerAction(player, 3);
			SlimeAction(slime, 1);
			Sleep(1000);
			
			
			
		}
		if (slime->health <= 0)
		{
			system("cls");                 // 안지우면 막타모션이 안보임

			ShowStage(Stage, 0, 0);
			ShowGold(&inventory);

			slimeCount++;
			
			
			GoToXY(2, 4);
			printf("보스 몬스터 소환 %d / 5", slimeCount);
			//SlimeGoldDrop(&slime, &inventory);
			
			slime->health = 0;
			PlayerAction(player, 1);
			SlimeAction(slime, 3);

			Sleep(1000);					
		}
	}
	ShowAttack++;

	Sleep(500);
}

void BattleWithBoss(Character* player, BossCharacter* boss)
{
	ShowStage(Stage, 0, 0);
	ShowGold(&inventory);

	static int ShowAttack = true;

	if (ShowAttack % 2 != false)
	{
		BossAction(boss, 1);
		PlayerAction(player, 1);
	}
	else
	{
		player->health -= boss->attack;
		boss->health -= player->attack;

		BossAction(boss, 2);
		PlayerAction(player, 2);

		if (player->health <= 0)
		{
			system("cls");                  // 막타

			ShowStage(Stage, 0, 0);
			ShowGold(&inventory);

			player->health = 0;
			player->action3;
			BossAction(boss, 4);

			Sleep(1000);
		}
		if (boss->health <= 0)
		{
			system("cls");                    // 막타

			boss->health = 0;

			ShowStage(Stage, 0, 0);
			ShowGold(&inventory);
			BossGoldDrop(&boss, &inventory);
			PlayerAction(player, 1);
			BossAction(boss, 3);
			
			Sleep(1000);

			
		}
	}
	ShowAttack++;
	Sleep(500);
}






