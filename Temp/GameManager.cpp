#include "GameManager.h"
#include <Windows.h>
#include <iostream>

GameManager::GameManager()
    : player(10, 10, 11, 1000, "�ٹٸ���", SwordIdle),
    monster(36, 10, 6, 50, "������", SlimeIdle),
    boss(36, 10, 60, 500, "ŷ������", KingSlimeIdle),
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
    cout << "�������� Ŭ����!" << endl;
    GoToXY(10, 4);
    cout << "1. ���� ����������" << endl;
    GoToXY(10, 5);
    cout << "2. ���� ����" << endl;

    int input;
    while (true) 
    {
        GoToXY(10, 7);
        cout << "����: ";
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
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.";
        }
    }
}
