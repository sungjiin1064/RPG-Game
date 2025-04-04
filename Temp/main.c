
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
	printf("전투중...");
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

//                   x   y  공 피  이름  액션1(기본)  액션2(공격)  액션3(사망)
Character player = { 10,10,11,100,"유저","(  '' )/","(  '' )ㅡE","__+__" };
Character slime = { 40,10,4,20,"슬라임"," ( ''  )","( ''   )"," ( x x )" };

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

			if (slime.health <= 0)                 // 이코드를 battle안에 넣을순 없나?
			{
				StartPosition(&player, &slime);     // 막타가 액션 2동작때 피가 0보이게할려고
				BattleWithslime(&player, &slime);   // 막타모션이 없고 리젠몬스터가 다가왔을때 모션2 부터 시작

				GoToXY(player.x, player.y);  // 무기 잔상 없애기
				printf("          ");
				GoToXY(player.x, player.y-2);  // 몬스터가 한방컷 나면 100에서 뒤에 0 잔상이남음
				printf("         ");
				GoToXY(slime.x, slime.y -2);  // 몬스터가 한방컷 나면 체력이 00이 보여서 뒤에0이 잔상인거 같음
				printf("           ");

				StartPosition(&player, &slime);     // 잔상없앤거 보여주기위해서	

				GoToXY(slime.x, slime.y);
				printf("%s", slime.action3);				
				
				Sleep(1000);

				SlimeRespawn(&slime);

			}

		}

	}
	return;

}