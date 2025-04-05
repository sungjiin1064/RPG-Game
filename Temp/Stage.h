#include <Windows.h>
#include <stdio.h>   
#include <stdbool.h>
#include <conio.h>   // _kbhit
#include <stdlib.h> // exit

#define STAGE_WIDTH 60
#define STAGE_HEIGHT 12

void GoToXY(int x, int y);

void ShowStage(char(*Stage)[STAGE_WIDTH], int x, int y);

char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1];

void GameStart();

//char KingSlimeStage[STAGE_HEIGHT][STAGE_WIDTH + 1];

