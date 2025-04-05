#define SLIME_WIDTH 11
#define SLIME_HEIGHT 3

#include "Stage.h"

char SlimeWALK[SLIME_HEIGHT][SLIME_WIDTH + 1];
char SlimeFIGHT[SLIME_HEIGHT][SLIME_WIDTH + 1];
char SlimeDEAD[SLIME_HEIGHT][SLIME_WIDTH + 1];

void SlimeMove(char (*Slime)[SLIME_WIDTH + 1], int x, int y);