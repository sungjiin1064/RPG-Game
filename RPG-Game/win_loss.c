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
	printf("�ɸ��Ͱ� ����Ͽ����ϴ�...");
	setCursorPos(playerX - 4, playerY - 2);
	printf("��� ü��: %d", playerHealth);
	setCursorPos(monsterX, monsterY - 2);
	printf("������ ü�� : %d", monsterHealth);
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
	printf("������ ü�� : %d", monsterHealth);
	setCursorPos(playerX - 4, playerY - 2);
	printf("��� ü��: %d", playerHealth);
	setCursorPos(playerX + 3, playerY - 5);
	printf("�������� óġ�Ͽ����ϴ�.\n");
	setCursorPos(x, y);
	printf("               ");
	setCursorPos(x, y);
	printf(" (x . x)");
}
#endif // 0
