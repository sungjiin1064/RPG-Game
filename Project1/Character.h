
#define SLIME_WIDTH 12
#define SLIME_HEIGHT 3

#include <Windows.h>
#include <stdio.h>   
#include <stdbool.h>
#include <conio.h>   // _kbhit
#include <stdlib.h> // exit
#include <time.h>

void GoToXY(int x, int y);

typedef struct
{
	int x, y, attack, health;
	char name[20];
	char action1[SLIME_WIDTH + 1];
	char action2[SLIME_WIDTH + 1];
	char action3[SLIME_WIDTH + 1];
	char action4[SLIME_WIDTH + 1];
}Character;

typedef struct
{
	int x, y, attack, health;
	char name[20];
	char action1[SLIME_HEIGHT][SLIME_WIDTH + 1];
	char action2[SLIME_HEIGHT][SLIME_WIDTH + 1];
	char action3[SLIME_HEIGHT][SLIME_WIDTH + 1];
	char action4[SLIME_HEIGHT][SLIME_WIDTH + 1];
}BossCharacter;

Character player, slime;
BossCharacter boss;

void SlimeRespawn(Character* slime);

void StartPosition(Character* player, Character* slime);

void PlayerAction(Character* player, int action);

void BossAction(BossCharacter* boss, int action);

typedef struct
{
	int x, y, gold;
}Inventory;

Inventory inventory;

void SlimeGoldDrop(Character* slime, Inventory* inventory);

void BossGoldDrop(Character* boss, Inventory* inventory);

void ShowGold(Inventory* inventory);