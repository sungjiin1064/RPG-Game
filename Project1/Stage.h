
#include <Windows.h>
#include <stdbool.h>


#define STAGE_WIDTH 60
#define STAGE_HEIGHT 12

void GameStart();

char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1];

void ShowStage(char(*stage)[STAGE_WIDTH+1], int x, int y);

