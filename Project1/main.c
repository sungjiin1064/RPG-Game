
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
				printf("���� ���� ��ȯ %d / 5", slimeCount);
				SlimeGoldDrop(&slime, &inventory);

				//Sleep(1000);
				if (slimeCount < 1) 
				{
					GoToXY(2, 4);
					printf("���� ���� ��ȯ %d / 5", slimeCount);
					SlimeRespawn(&slime);
					
				}
				else 
				{
					GoToXY(2, 4);
					printf("���� ���� ��ȯ..      3");
					Sleep(1000);
					GoToXY(2, 4);
					printf("���� ���� ��ȯ....    2");
					Sleep(1000);
					GoToXY(2, 4);
					printf("���� ���� ��ȯ......  1");
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
				printf("���� ���͸� óġ�Ͽ����ϴ�!\n");
				BossAction(&boss, 3);
				GoToXY(boss.x, boss.y - 2);
				printf("              ");
				GoToXY(boss.x, boss.y - 1);
				printf("   �� ��     ");
				GoToXY(boss.x, boss.y );
				printf("    ��         ");
				PlayerAction(&player, 4);
				GoToXY(player.x, player.y - 2);
				printf("  ��  ��  ");
				GoToXY(0,14);
							
				break;
			}
		}

		if (player.health <= 0) 
		{
			GoToXY(player.x, player.y - 2);
			printf("  ��  ��  ");
			PlayerAction(&player, 3);
			GoToXY(2, 2);
			printf("�ɸ��Ͱ� ����Ͽ����ϴ�!\n");
			GoToXY(0, 14);
			

			break;
		}
	}

	return 0;
}