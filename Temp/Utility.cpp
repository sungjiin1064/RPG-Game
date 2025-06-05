#include "Utility.h"

void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Random()
{
	srand(time(0));
}
