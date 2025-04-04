#include "Stage.h"

void GoToXY(int x, int y) 
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GOToXYCOORD(COORD _pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);
}

void ShowStage(char(*Stage)[STAGE_WIDTH], COORD pos)
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		GoToXY(pos.X, pos.Y);
		printf("%s", Stage[0]);
	}
	
}

char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1] =  // ""사용할려면  +1
{
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",	
	"#                  #",
	"####################"
};

