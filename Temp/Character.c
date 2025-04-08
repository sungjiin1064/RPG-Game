#include "Character.h"

char SlimeWALK[SLIME_HEIGHT][SLIME_WIDTH + 1] =
{
	"   - -",
	" - ..  -",
	" _ _ _ _ _ "
};

char SlimeFIGHT[SLIME_HEIGHT][SLIME_WIDTH + 1] =
{
	" - -",
	"- ..  -",
	" _ _ _ _ _ "
};

char SlimeDEAD[SLIME_HEIGHT][SLIME_WIDTH + 1] =
{
	" - - - - -",
	"'_ _x x_ _'"
};

void KingSlime(char(*Slime)[SLIME_WIDTH + 1], int x, int y)
{
	for (int i = 0; i < SLIME_HEIGHT; i++)
	{		
		GoToXY(x ,y + i);
		printf("%s \n", Slime[i]);
	}
}
