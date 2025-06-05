#include "GameManager.h"
#include <Windows.h>
#include <iostream>

GameManager::GameManager()
    : player(10, 10, 11, 1000, "바바리안", SwordIdle),
    monster(36, 10, 6, 50, "슬라임", SlimeIdle),
    boss(36, 10, 60, 500, "킹슬라임", KingSlimeIdle),
    killCount(0), bossSpawned(false) {}

void GameManager::Run()
{
    Random();
    Loop();
}

void GameManager::Loop() 
{
    while (true) 
    {
        monster.ShowGold();
        GoToXY(0, 15);
        cout << "=================================================";
        player.ShowImage();

        if (!bossSpawned) 
        {
            monster.Move(player);
            if (monster.HP == 0) 
            {
                killCount++;
                monster.DropGold();
                if (killCount < 2)
                {
                    RespawnMonster();
                }
                else
                {
                    RespawnBoss();
                }
            }
        }
        else
        {
            boss.Move(player);
            if (boss.HP == 0)
            {
                HandleStageClear();
            }
        }
    }
}

void GameManager::RespawnMonster() 
{
    monster.Respawn();
    player.ChangeImage(SwordIdle);
}

void GameManager::RespawnBoss()
{
    bossSpawned = true;
    boss.BossRespawn();
    player.ChangeImage(SwordIdle);
}

void GameManager::HandleStageClear()
{
    system("cls");
    GoToXY(10, 2);
    cout << "스테이지 클리어!" << endl;
    GoToXY(10, 4);
    cout << "1. 다음 스테이지로" << endl;
    GoToXY(10, 5);
    cout << "2. 게임 종료" << endl;

    int input;
    while (true) 
    {
        GoToXY(10, 7);
        cout << "선택: ";
        cin >> input;
        if (input == 1)
        {
            killCount = 0;
            bossSpawned = false;
            monster.totalGold = boss.totalGold;
            monster.HP = 50;
            system("cls");
            break;
        }
        else if (input == 2)
        {
            exit(0);
        }
        else 
        {
            GoToXY(10, 8);
            cout << "잘못된 입력입니다. 다시 입력하세요.";
        }
    }
}
