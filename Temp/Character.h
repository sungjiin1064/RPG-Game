#define SLIME_WIDTH 10
#define SLIME_HEIGHT 10

#include "Stage.h"

char SlimeWALK[SLIME_HEIGHT][SLIME_WIDTH + 1];
char SlimeFIGHT[SLIME_HEIGHT][SLIME_WIDTH + 1];
char SlimeDEAD[SLIME_HEIGHT][SLIME_WIDTH + 1];

void SlimeMove(char (*slime)[SLIME_WIDTH + 1], int x, int y);