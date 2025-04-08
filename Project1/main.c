
//#include "Move.h"
//#include "Battle.h"
#include "Character.h"
#include "Stage.h"

int main()
{
	//GameStart();
	srand(time(NULL));
	
	
	int slimeCount = 0;
	int bossSpawn = 0;

	while (1) 
	{
		system("cls");

		ShowStage(Stage,0,0);
		ShowGold(&inventory);
		

		if (bossSpawn == 0)
		{			
			StartPosition(&player, &slime);			
			MoveSlime(&slime, &player);
			BattleWithSlime(&player, &slime,slimeCount);
			//SlimeGoldDrop(&slime, &inventory);
									
			if (slime.health <= 0) 
			{		
				
				slimeCount++;
				GoToXY(2, 4);
				printf("보스 몬스터 소환 %d / 5", slimeCount);
				SlimeGoldDrop(&slime, &inventory);

				//Sleep(1000);
				if (slimeCount < 1) 
				{
					GoToXY(2, 4);
					printf("보스 몬스터 소환 %d / 5", slimeCount);
					SlimeRespawn(&slime);
					
				}
				else 
				{
					GoToXY(2, 4);
					printf("보스 몬스터 소환..      3");
					Sleep(1000);
					GoToXY(2, 4);
					printf("보스 몬스터 소환....    2");
					Sleep(1000);
					GoToXY(2, 4);
					printf("보스 몬스터 소환......  1");
					Sleep(1000);
					bossSpawn = 1; 			
				}
			}
		}
		else 
		{			
			MoveBoss(&boss, &player);
			
			BattleWithBoss(&player, &boss);

			if (boss.health <= 0) 
			{
				system("cls");

				ShowStage(Stage, 0, 0);

				GoToXY(2, 2);
				printf("보스 몬스터를 처치하였습니다!\n");
				BossAction(&boss, 3);
				GoToXY(boss.x, boss.y - 2);
				printf("              ");
				GoToXY(boss.x, boss.y - 1);
				printf("   ⊂ ⊃     ");
				GoToXY(boss.x, boss.y );
				printf("    ζ         ");
				PlayerAction(&player, 4);
				GoToXY(player.x, player.y - 2);
				printf("  승  리  ");
				GoToXY(0,14);
							
				break;
			}
		}

		if (player.health <= 0) 
		{
			GoToXY(player.x, player.y - 2);
			printf("  사  망  ");
			PlayerAction(&player, 3);
			GoToXY(2, 2);
			printf("케릭터가 사망하였습니다!\n");
			GoToXY(0, 14);
			

			break;
		}
	}

	return 0;
}