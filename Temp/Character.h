#pragma once

#include "Image.h"
#include "Common.h"

class Character
{
public:
    int X;
    int Y;
    int ATK;
    int HP;
    std::string NAME;
    char IMAGE[UNIT_HEIGHT][UNIT_WIDTH + 1];

    Character(int posX, int posY, int attack, int hp, std::string name, char image[UNIT_HEIGHT][UNIT_WIDTH + 1]);
    void ChangeImage(char image[UNIT_HEIGHT][UNIT_WIDTH + 1]);
};

