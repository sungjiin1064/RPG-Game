#pragma once

#include "Character.h"
#include "Player.h"

class Monster : public Character
{
public:
    bool isBoss = false;
    int gold = 0;
    int totalGold = 0;

    Monster(int posX, int posY, int attack, int hp, string name, char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
        : Character(posX, posY, attack, hp, name, image) {}

    void ShowImage();
    void Move(Player& player);
    void Battle(Player& player);
    void Respawn();
    void BossRespawn();
    void BossIntro();
    void DropGold();
    void ShowGold();
};