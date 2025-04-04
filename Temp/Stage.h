#include <Windows.h>
#include <stdio.h>   
#include <stdbool.h>

#define STAGE_WIDTH 40
#define STAGE_HEIGHT 10

void GoToXY(int x, int y);



void ShowStage(char(*Stage)[STAGE_WIDTH], COORD pos);

char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1];

char KingSlimeStage[STAGE_HEIGHT][STAGE_WIDTH + 1];