#include "Player.h"
#include <iostream>

void Player::ShowImage() 
{
    for (int y = 0; y < UNIT_HEIGHT; y++)
    {
        for (int x = 0; x < UNIT_WIDTH + 1; x++)
        {
            GoToXY(X + x, Y + y);
            std::cout << IMAGE[y][x];
        }
    }
    GoToXY(X + 3, Y + UNIT_HEIGHT + 2);
    std::cout << "HP :       ";
    GoToXY(X + 3, Y + UNIT_HEIGHT + 2);
    std::cout << "HP : " << HP;
}
