
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

				//BossCount(slimeCount);
				SlimeGoldDrop(&slime, &inventory);
				
				if (slimeCount < 2) 
				{					
					SlimeRespawn(&slime);					
				}
				else 
				{
					BossLoading();

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
				BossDead(&boss, &player);							
				break;
			}
		}
		if (player.health <= 0) 
		{
			PlayerDead(&player,&slime);
			break;
		}
	}
	return 0;
}

#include <Windows.h>
#include <stdio.h>   
#include <stdbool.h>
#include <conio.h>   // _kbhit
#include <stdlib.h> // exit
#include <time.h>


