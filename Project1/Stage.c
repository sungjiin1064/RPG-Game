
#include "Stage.h"

void ShowStage(char(*Stage)[STAGE_WIDTH + 1], int x, int y)
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		GoToXY(x, y + i);
		printf("%s\n", Stage[i]);
	}
}

char Stage[STAGE_HEIGHT][STAGE_WIDTH + 1] =  // ""����ҷ���  +1
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
	int L = 4;
	int R = 4;

	while (1)
	{
		system("cls");

		ShowStage(Stage, 0, 0);

		GoToXY(8, L);
		printf("(  '' )��E");
		GoToXY(34, R);
		printf(" ( ''  )");

		GoToXY(20, 3);
		printf("��������������������������");
		GoToXY(20, 4);
		printf("��  ���ӽ��� �� ");
		GoToXY(20, 5);
		printf("��������������������������");
		GoToXY(20, 6);
		printf("��������������������������");
		GoToXY(20, 7);
		printf("��  �������� �� ");
		GoToXY(20, 8);
		printf("��������������������������");

		Sleep(100);

		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				L -= 3;
				R -= 3;
				if (L < 4 || R < 4)
				{
					L = 4;
					R = 4;
				}
				Sleep(50);
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				L += 3;
				R += 3;
				if (L > 7 || R> 7)
				{
					L = 7;
					R = 7;
				}
				Sleep(50);
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{
				if (L == 4)
				{
					GoToXY(12, 13);
					printf("- ����� ������ �����մϴ�. -");
					Sleep(1000);
					GoToXY(12, 13);
					printf("- ����� ������ �����մϴ�. -  3");
					Sleep(1000);
					GoToXY(12, 13);
					printf("- ����� ������ �����մϴ�. -  2");
					Sleep(1000);
					GoToXY(12, 13);
					printf("- ����� ������ �����մϴ�. -  1");
					Sleep(1000);

					return;
				}
				else if (L == 7)
				{
					GoToXY(15, 13);
					printf("< ������ �����Ͽ����ϴ�. >");
					GoToXY(0, 14);
					exit(0);
				}
				

			}
		}
		Sleep(100);
	}
	return;

}