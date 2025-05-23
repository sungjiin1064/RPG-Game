
#include "Character.h"
#include "Stage.h"

void GoToXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void StartPosition(Character* player, Character* slime)
{
	GoToXY(player->x - 1, player->y - 2);
	printf("%s : %d", player->name, player->health);
	GoToXY(slime->x + 1, slime->y - 2);
	printf("%s : %d", slime->name, slime->health);
}

void PlayerAction(Character* player, int action)
{
	GoToXY(player->x - 1, player->y - 2);
	printf("%s : %d", player->name, player->health);
	GoToXY(player->x, player->y);
	if (action == 1)
	{
		printf("%s", player->action1);
	}
	else if (action == 2) printf("%s", player->action2);
	else if (action == 3) printf("%s", player->action3);
	else if (action == 4) printf("%s", player->action4);
}

void SlimeAction(Character* slime, int action)
{
	GoToXY(slime->x + 1, slime->y - 2);
	printf("%s : %d", slime->name, slime->health);
	GoToXY(slime->x, slime->y);
	if (action == 1) printf("%s", slime->action1); // 기본 상태
	else if (action == 2) printf("%s", slime->action2); // 공격 상태
	else if (action == 3) printf("%s", slime->action3); // 사망 상태
	else if (action == 4) printf("%s", slime->action4);
}

void BossAction(BossCharacter* boss, int action)
{
	for (int i = 0; i < SLIME_HEIGHT; i++)
	{
		GoToXY(boss->x, boss->y - 2);
		printf("%s : %d", boss->name, boss->health);
		GoToXY(boss->x, boss->y + i);
		if (action == 1) printf("%s", boss->action1[i]); // 기본 상태
		else if (action == 2) printf("%s", boss->action2[i]); // 공격 상태
		else if (action == 3) printf("%s", boss->action3[i]); // 사망 상태
		else if (action == 4) printf("%s", boss->action4[i]); 
	}
}

void SlimeRespawn(Character* slime)
{
	SlimeGoldDrop(slime, &inventory);
	slime->x = 52;
	slime->health = 100;	
}
//                   x   y   공   피
Character player = { 25, 10, 31, 1150, "기 사",  "(  '' )/", "(  '' )ㅡE", "__+__","\\(  ''  )/" };
Character slime = {  52, 10, 11, 100, "슬라임"," ( ''  )","( ''   )"," ( x x )", " ( 'v' )"};
BossCharacter boss =
{// x   y  공   피
	52, 8, 22, 100, "킹 슬라임",
	{
		"   - -",
		" - ..  -",
		"_ _ _ _ _ _"
	},
	{
		" - -",
		"- ..  -",
		" _ _ _ _ _ "
	},
	{
		"         ",
		" - - - - -",
		"'_ _x x_ _'"
	},
	{
		"   -  -",
		" - .   . -",
		"_ _ _v_ _ _"
	}
};

Inventory inventory = { 70,4,0 };

void SlimeGoldDrop(Character* slime, Inventory* inventory)
{
	int goldDrop = rand() % 51 + 50;
	if (slime->health <= 0)
	{
		goldDrop++;
		inventory->gold += goldDrop;
	}

	GoToXY(inventory->x, inventory->y);
	printf("소지금화 : %d gold", inventory->gold);
}

void BossGoldDrop(Character * boss, Inventory * inventory)
{
	int bigGoldDrop = rand() % 201 + 200;
	if (boss->health <= 0)
	{
		bigGoldDrop++;
		inventory->gold += bigGoldDrop;
	}
	GoToXY(inventory->x, inventory->y);
	printf("소지금화 : %d gold", inventory->gold);
}

void ShowGold(Inventory* inventory)
{
	GoToXY(inventory->x, inventory->y);
	printf("소지금화 : %d gold", inventory->gold);
}

void PlayerDead(Character* player, Character* slime)
{	
	ShowStage(Stage, 0, 0);
		
	SlimeAction(slime, 4);
	PlayerAction(player, 3);

	GoToXY(player->x-2, player->y - 2);
	printf(" L O S E  ");
	GoToXY(slime->x+1, slime->y - 2);
	printf(" W I N          ");
	GoToXY(2, 2);
	printf("케릭터가 사망하였습니다!\n");

	GoToXY(0, 14);
}

void BossDead(BossCharacter* boss, Character* player)
{
	BossAction(boss, 3); 
	PlayerAction(player, 4);         
	
	GoToXY(boss->x-2, boss->y - 2);
	printf("    L O S E       ");
	GoToXY(boss->x, boss->y - 1);
	printf("   ⊂ ⊃     ");
	GoToXY(boss->x, boss->y);
	printf("    ζ               ");	
	GoToXY(player->x - 2, player->y - 2);
	printf("    W I N   ");

	GoToXY(2, 2);
	printf("보스 몬스터를 처치하였습니다!\n");

	GoToXY(0, 14);
}

void BossLoading()
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
}



