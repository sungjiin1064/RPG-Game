#include "Character.h"

char SlimeWALK[SLIME_HEIGHT][SLIME_WIDTH + 1] =
{
	"   - -",
	" - ..  -",
	"- - - - -"
};

char SlimeFIGHT[SLIME_HEIGHT][SLIME_WIDTH + 1] =
{
	" - -",
	"- ..  -",
	"- - - - -"
};

char SlimeDEAD[SLIME_HEIGHT][SLIME_WIDTH + 1] =
{
	" - - - - -",
	"'_ _x x_ _'"
};

void SlimeMove(char(*slime)[SLIME_WIDTH + 1], int x , int y)
{
	for (int i = 0; i < SLIME_HEIGHT; i++)
	{		
		GoToXY(x, y + i);
		printf("%s \n", slime[i]);
	}
}
