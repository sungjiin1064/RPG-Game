#include "Enemy.h"

void Enemy::ShowImage()
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

void Enemy::Move(Player* player)
{

	if (X >= 20)
	{
		X--;
	}
	else
	{
		X = 20;
		Battle(player, *this);
	}
}

void Enemy::ChangeImage(char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
{
	for (int y = 0;y < UNIT_HEIGHT;y++)
	{
		for (int x = 0;x < UNIT_WIDTH + 1;x++)
		{
			IMAGE[y][x] = image[y][x];
		}
	}
}

void Enemy::SetBattle(char image[UNIT_HEIGHT][UNIT_WIDTH + 1],Player* player)
{
	ChangeImage(image);
	ShowImage();
	Move(player);
}

void Enemy::Battle(Player* player, Enemy enemy)
{

	static bool ShowAttack = true;

	if (ShowAttack)
	{
		player->SetBattle(ArrowBattle);
		enemy.SetBattle(SlimeBattle);
	}
	else
	{
		player->SetBattle(ArrowIdle);
		enemy.SetBattle(SlimeIdle);
	}
	ShowAttack = !ShowAttack;
	Sleep(500);
}


