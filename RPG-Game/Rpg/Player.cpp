#include "Player.h"

void Player::ShowImage()
{
	for (int y = 0; y < UNIT_HEIGHT;y++)
	{
		for (int x = 0; x < UNIT_WIDTH + 1; x++)
		{
			GoToXY(X + x, Y + y);
			cout << Image[y][x];
		}
		cout << endl;
	}
}
