#include "Character.h"

void Character::ChangeImage(char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
{
	for (int y = 0; y < UNIT_HEIGHT;y++)
	{
		for (int x = 0;x < UNIT_WIDTH + 1;x++)
		{
			IMAGE[y][x] = image[y][x];
		}
	}
	
}


