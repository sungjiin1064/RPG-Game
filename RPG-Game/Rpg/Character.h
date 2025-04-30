#pragma once



class Character
{
public:
	int posX;
	int posY;
	int attack;
	int hp;
	string name;
	char Image[UNIT_HEIGHT][UNIT_WIDTH + 1];

	Character(int posX, int posY, int attack, int hp, string name, char Image[UNIT_HEIGHT][UNIT_WIDTH + 1]) :
		posX(posX), posY(posY), attack(attack), hp(hp), name(name)
	{
		for (int y = 0;y < UNIT_HEIGHT;y++)
		{
			for (int x = 0;x < UNIT_WIDTH;x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}

	}


};

