#include <stdbool.h>
#include <stdio.h>
#include <Windows.h>

void setCursorPos(int x, int y);

void startPosition();

typedef struct
{
	int x, y, health, attack;
	char action1[20];
	char action2[20];
	char action3[20];	
}Character;

typedef struct
{
	int x, y, health, attack;
	char action1[3][10];
	char action2[3][10];
	char action3[2][12];
}CharacterKing;

Character player;
//Character monster;
Character slime;
CharacterKing Slime;


char kingSlimeBasic[3][10];
//{
//	"   - -",
//	" - ..  -",
//	"- - - - -"
//};
char kingSlimeAttack[3][10];
//{
//	" - -",
//	"- ..  -",
//	"- - - - -"
//};
char kingSlimeDie[2][12];
//{	
//	" - - - - -",
//	"'_ _x x_ _'"
//};