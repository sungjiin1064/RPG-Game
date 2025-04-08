
#include "Stage.h"

void ShowStage(char(*Stage)[STAGE_WIDTH + 1], int x, int y)
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		GoToXY(x, y + i);
		printf("%s\n", Stage[i]);
	}

}

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
	int Lmouse = 4;
	int Rmouse = 4;

	while (1)
	{
		system("cls");

		ShowStage(Stage, 0, 0);

		GoToXY(4, Lmouse);
		printf("(  '' )ㅡE");
		GoToXY(29, Rmouse);
		printf(" ( ''  )");

		GoToXY(16, 3);
		printf("┌──────────┐");
		GoToXY(16, 4);
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
				Lmouse -= 3;
				Rmouse -= 3;
				if (Lmouse < 4 || Rmouse < 4)
				{
					Lmouse = 4;
					Rmouse = 4;
				}
				Sleep(50);
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				Lmouse += 3;
				Rmouse += 3;
				if (Lmouse > 7 || Rmouse > 7)
				{
					Lmouse = 7;
					Rmouse = 7;
				}
				Sleep(50);
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{
				if (Lmouse == 4)
				{
					GoToXY(12, 13);
					printf("- 잠시후 게임을 시작합니다. -");
					Sleep(1000);
					GoToXY(12, 13);
					printf("- 잠시후 게임을 시작합니다. -  3");
					Sleep(1000);
					GoToXY(12, 13);
					printf("- 잠시후 게임을 시작합니다. -  2");
					Sleep(1000);
					GoToXY(12, 13);
					printf("- 잠시후 게임을 시작합니다. -  1");
					Sleep(1000);

					return;
				}
				else if (Lmouse == 7)
				{
					GoToXY(15, 13);
					printf("< 게임을 종료하였습니다. >");
					GoToXY(0, 14);
					exit(0);
				}
				

			}
		}
		Sleep(100);
	}
	return;

}