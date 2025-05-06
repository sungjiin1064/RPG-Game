#include "Player.h"

void Player::ShowImage()
{
	for (int y = 0;y < UNIT_HEIGHT;y++)
	{
		for (int x = 0;x < UNIT_WIDTH + 1;x++)
		{
			GoToXY(X + x, Y + y);
			cout << IMAGE[y][x];
		}
		cout << endl;
	}
}

void Player::ChangeImage(char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
{
	for (int y = 0;y < UNIT_HEIGHT;y++)
	{
		for (int x = 0;x < UNIT_WIDTH + 1;x++)
		{			
			IMAGE[y][x] = image[y][x];
		}
		
	}
}

void Player::SetBattle(char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
{
	ChangeImage(image);
	ShowImage();
}
