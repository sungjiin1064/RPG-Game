#include "Monster.h"
#include "Utility.h"
#include "Image.h"
#include <iostream>
#include <Windows.h>

void Monster::ShowImage()
{
	for (int y = 0; y < UNIT_HEIGHT; y++)
		for (int x = 0; x < UNIT_WIDTH + 1; x++)
		{
			GoToXY(X + x, Y + y);
			cout << IMAGE[y][x];
		}
	GoToXY(X + 2, Y + UNIT_HEIGHT + 2);
	cout << "HP :      ";
	GoToXY(X + 2, Y + UNIT_HEIGHT + 2);
	cout << "HP : " << HP;
}

void Monster::Move(Player& player)
{
	if (X < 26)
	{
		Sleep(300);
		Battle(player);
	}
	else
	{
		ChangeImage(isBoss ? KingSlimeMove : SlimeMove);
		ShowImage();
		Sleep(150);
		ChangeImage(isBoss ? KingSlimeIdle : SlimeIdle);
		ShowImage();
		Sleep(150);
		X--;
	}
}

void Monster::Battle(Player& player)
{
    static bool isBattlePhase = true;

    while (player.HP > 0 && HP > 0)
    {
        if (isBattlePhase)
        {
            // ���� �� �ǰ� ó�� - ��Ʋ �̹��� ����
            player.HP -= ATK;
            if (player.HP < 0)
                player.HP = 0;

            HP -= player.ATK;
            if (HP < 0)
                HP = 0;

            // ��Ʋ �̹��� �����ֱ�
            if (isBoss)
                ChangeImage(KingSlimeBattle);
            else
                ChangeImage(SlimeBattle);

            ShowImage();

            player.ChangeImage(SwordBattle);
            player.ShowImage();
        }
        else
        {
            // ���̵� �̹��� ���� (���� ����)
            if (isBoss)
                ChangeImage(KingSlimeIdle);
            else
                ChangeImage(SlimeIdle);

            ShowImage();

            player.ChangeImage(SwordIdle);
            player.ShowImage();
        }

        isBattlePhase = !isBattlePhase; // ��Ʋ<->���̵� ���

        Sleep(300);
    }

    // ���Ͱ� �׾����� ���̵� �̹����� �ѹ� �����ְ� ���� ó��
    if (HP == 0)
    {
        if (isBoss)
            ChangeImage(KingSlimeIdle);
        else
            ChangeImage(SlimeIdle);

        ShowImage();

        Sleep(500); // ���̵� �̹��� ��� �����ֱ�

        killCount++;        // ���� ���� ī��Ʈ ����
        DropGold();     // ��� ��� ����
        ShowGold();     // ���� ��� ���
    }

    // �÷��̾ ������ ���� ����
    if (player.HP == 0)
    {
        system("cls");
        GoToXY(10, 2);
        cout << "Game Over" << endl;
        Sleep(1000);
        exit(0);
    }
}





void Monster::Respawn()
{
	X = 36;
	HP = 50;
	Sleep(500);
	system("cls");
}

void Monster::BossIntro()
{
	GoToXY(10, 2);
	cout << "����� ������ �����մϴ�.....3" << endl;
	Sleep(1000);
	GoToXY(10, 2);
	cout << "����� ������ �����մϴ�...  2" << endl;
	Sleep(1000);
	GoToXY(10, 2);
	cout << "����� ������ �����մϴ�.    1" << endl;
	Sleep(1000);
}

void Monster::BossRespawn()
{
	BossIntro();
	X = 36;
	HP = 100;
	isBoss = true;
}

void Monster::DropGold()
{
	gold = rand() % 50 + 51;
	totalGold += gold;
}

void Monster::ShowGold()
{
	GoToXY(54, 2);
	cout << "���� �����ݾ� : " << totalGold;
}