#if 0
#include "Win_loss.h"

void playerWin(int x, int y)
{
	setCursorPos(x, y);
	printf("             ");
	setCursorPos(x, y);
	printf("( ^.^ )v");
}

void playerDie(int x, int y)
{
	setCursorPos(playerX + 3, playerY - 5);
	printf("케릭터가 사망하였습니다...");
	setCursorPos(playerX - 4, playerY - 2);
	printf("기사 체력: %d", playerHealth);
	setCursorPos(monsterX, monsterY - 2);
	printf("슬라임 체력 : %d", monsterHealth);
	setCursorPos(x, y);
	printf("             ");
	setCursorPos(x, y);
	printf("(x . x)");
}

void monsterWin(int x, int y)
{
	setCursorPos(x, y);
	printf("             ");
	setCursorPos(x, y);
	printf("v( ^.^ )");
}

void monsterDie(int x, int y)
{
	setCursorPos(monsterX, monsterY - 2);
	printf("슬라임 체력 : %d", monsterHealth);
	setCursorPos(playerX - 4, playerY - 2);
	printf("기사 체력: %d", playerHealth);
	setCursorPos(playerX + 3, playerY - 5);
	printf("슬라임을 처치하였습니다.\n");
	setCursorPos(x, y);
	printf("               ");
	setCursorPos(x, y);
	printf(" (x . x)");
}
#endif // 0
