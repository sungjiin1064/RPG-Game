#pragma once
#include "Player.h"
#include "Monster.h"
#include "Utility.h"

class GameManager 
{
public:
    GameManager();
    void Run();

private:
    void Loop();
    void HandleStageClear();
    void RespawnMonster();
    void RespawnBoss();

private:
    Player player;
    Monster monster;
    Monster boss;
    int killCount;
    bool bossSpawned;
};