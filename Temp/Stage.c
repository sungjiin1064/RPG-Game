#include "Stage.h"

void GoToXY(int x, int y) 
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ShowStage(char(*Stage)[STAGE_WIDTH +1], int x, int y)
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		GoToXY(x, y+i);
		printf("%s\n", Stage[i]);
	}
	
}

//char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1] =  // ""사용할려면  +1
//{
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",
//	"#                                                #",	
//	"#                                                #",
//	"##################################################"
//};

char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1] =  // ""사용할려면  +1
{
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"                                                            ",
	"############################################################"
};

void GameStart()
{
	int mouse = 4;

	while(1)
	{
		system("cls");

		GoToXY(4, mouse);
		printf("(  '' )ㅡE");
		GoToXY(16, 3);
		printf("┌──────────┐");
		GoToXY(16,4);
		printf("| 게임시작 |");
		GoToXY(16, 5);
		printf("└──────────┘");
		GoToXY(16, 6);
		printf("┌──────────┐");
		GoToXY(16, 7);
		printf("| 게임종료 |");
		GoToXY(16, 8);
		printf("└──────────┘");

		Sleep(100);

		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				mouse -= 3;
				if (mouse < 4)
				{
					mouse = 4;
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				mouse += 3;
				if (mouse > 7)
				{
					mouse = 7;
				}
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{ 
				if (mouse == 4)
				{
					return;
				}
				else if (mouse == 7)
				{
					exit(0);
				}
			}
			
		}
	}
	return;
}

