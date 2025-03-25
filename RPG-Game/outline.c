#if 0
#include "outline.h"

void line()
{
	printf("■              ★            ★                                                                      ■\n");
	printf("■           ★     ★  ★  ★                                                                        ■\n");
	printf("■             ★                                                                                     ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                            _________________                       ■\n");
	printf("■                                                           |                 |                      ■\n");
	printf("■                                                           |                 |                      ■\n");
	printf("■                                                           |                 |                      ■\n");
	printf("■                                                           |                 |                      ■\n");
	printf("■                                                           |                 |                      ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

}

void GameOver()
{
	system("cls");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■                                                                                                    ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");


	setCursorPos(8, 2);
	printf("    --       --         -    -      - - -        --     -         -  - - -   - - -\n");
	setCursorPos(8, 3);
	printf("  -         -  -       - -  - -     -          -    -    -       -   -       -    -\n");
	setCursorPos(8, 4);
	printf(" -  ---    - -- -     -   - -  -    - - -    -        -   -     -    - - -   - - -\n");
	setCursorPos(8, 5);
	printf(" -    -   -      -   -     -    -   -          -    -      -   -     -       -   -\n");
	setCursorPos(8, 6);
	printf("   ----  -        -  -          -   - - -  =     --          -       - - -   -    -\n");
	setCursorPos(40, 14);
	printf("\n");

}

void GameStart()
{
	int mouseY = 5;

	while (1)
	{

		system("cls");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■                                                                                                    ■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

		setCursorPos(20, 5);
		printf("게임시작\n");

		setCursorPos(20, 6);
		printf("게임종료\n");

		setCursorPos(30, mouseY);
		printf("<--( ''  )\n");


		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				mouseY -= 1;
				if (mouseY < 5)
				{
					mouseY = 5;
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				mouseY += 1;
				if (mouseY > 6)
				{
					mouseY = 6;
				}
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
				if (mouseY == 5)
				{
					return;
				}
				else if (mouseY == 6)
				{
					system("cls");
					setCursorPos(8, 2);
					printf("    --       --         -    -      - - -        --     -         -  - - -   - - -\n");
					setCursorPos(8, 3);
					printf("  -         -  -       - -  - -     -          -    -    -       -   -       -    -\n");
					setCursorPos(8, 4);
					printf(" -  ---    - -- -     -   - -  -    - - -    -        -   -     -    - - -   - - -\n");
					setCursorPos(8, 5);
					printf(" -    -   -      -   -     -    -   -          -    -      -   -     -       -   -\n");
					setCursorPos(8, 6);
					printf("   ----  -        -  -          -   - - -  =     --          -       - - -   -    -\n");
					setCursorPos(40, 14);
					printf("\n");
					exit(0);
				}
		}





		Sleep(100);
	}
	return;
}

#endif // 0
