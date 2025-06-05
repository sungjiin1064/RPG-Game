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
            // 공격 및 피격 처리 - 배틀 이미지 상태
            player.HP -= ATK;
            if (player.HP < 0)
                player.HP = 0;

            HP -= player.ATK;
            if (HP < 0)
                HP = 0;

            // 배틀 이미지 보여주기
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
            // 아이들 이미지 상태 (쉬는 상태)
            if (isBoss)
                ChangeImage(KingSlimeIdle);
            else
                ChangeImage(SlimeIdle);

            ShowImage();

            player.ChangeImage(SwordIdle);
            player.ShowImage();
        }

        isBattlePhase = !isBattlePhase; // 배틀<->아이들 토글

        Sleep(300);
    }

    // 몬스터가 죽었으면 아이들 이미지로 한번 보여주고 종료 처리
    if (HP == 0)
    {
        if (isBoss)
            ChangeImage(KingSlimeIdle);
        else
            ChangeImage(SlimeIdle);

        ShowImage();

        Sleep(500); // 아이들 이미지 잠깐 보여주기

        killCount++;        // 죽은 몬스터 카운트 증가
        DropGold();     // 골드 드랍 설정
        ShowGold();     // 현재 골드 출력
    }

    // 플레이어가 죽으면 게임 종료
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
	cout << "잠시후 보스가 등장합니다.....3" << endl;
	Sleep(1000);
	GoToXY(10, 2);
	cout << "잠시후 보스가 등장합니다...  2" << endl;
	Sleep(1000);
	GoToXY(10, 2);
	cout << "잠시후 보스가 등장합니다.    1" << endl;
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
	cout << "현재 소지금액 : " << totalGold;
}