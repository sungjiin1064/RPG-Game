#pragma once

#include "Character.h"
#include "Utility.h"

class Player : public Character
{
public:
    Player(int posX, int posY, int attack, int hp, string name, char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
        : Character(posX, posY, attack, hp, name, image) { }
   
    void ShowImage();
};


