#include "Enemy.h"

int Count = 0;

void Enemy::ShowImage()
{	
	for (int y = 0; y < UNIT_HEIGHT;y++)
	{
		for (int x = 0;x < UNIT_WIDTH + 1;x++)
		{
			GoToXY(X + x, Y + y);
			cout << IMAGE[y][x];
		}
	}
	GoToXY(X+2, Y + UNIT_HEIGHT + 2);
	cout << "HP :      ";
	GoToXY(X+2, Y + UNIT_HEIGHT + 2);
	cout << "HP : " << HP;
}

void Enemy::Move(Player& player)
{

	if (X <= 26)
	{				
		Sleep(500);
		Battle(player);
	}
	else
	{
		if (isKingSlime)
		{
			ChangeImage(KingSlimeMove);
			ShowImage();
			Sleep(100);
			ChangeImage(KingSlimeIdle);
			ShowImage();
			Sleep(100);

			X--;
		}
		else
		{			
			ChangeImage(SlimeMove);
			ShowImage();
			Sleep(100);
			ChangeImage(SlimeIdle);
			ShowImage();			
			Sleep(100);

			X--;
		}
		
	}
}

void Enemy::Battle(Player& player) //
{
	static bool isBattleImage = true;
	while (player.HP > 0 && HP > 0)
	{
		if (isBattleImage)
		{
			player.HP -= ATK;
			if (player.HP <= 0)
			{
				player.HP = 0;			
			}			
			HP -= player.ATK;
			if (HP <= 0)
			{
				HP = 0;
				Count++;
			}
			ChangeImage(SlimeBattle);
			ShowImage();
			player.ChangeImage(SwordBattle);
			player.ShowImage();


		}
		else
		{
			ChangeImage(SlimeIdle);
			ShowImage();
			player.ChangeImage(SwordIdle);
			player.ShowImage();
		}
		isBattleImage = !isBattleImage;
		Sleep(300);
	}

	if (HP == 0)
	{
		if (Count < 2)
		{
			GoToXY(10, 0);
			cout << Count << " / 2" << endl;
			ChangeImage(SlimeIdle);
			ShowImage();
			player.ChangeImage(SwordIdle);
			player.ShowImage();

			Respawn();
		}
		else
		{

			X = 40;
			HP = 100;
			isKingSlime = true;
			Sleep(1000);
			system("cls");
			ChangeImage(KingSlimeIdle);
			ShowImage();
			player.ChangeImage(SwordIdle);
			player.ShowImage();
		}
	}

	if (player.HP == 0)
	{
		exit(0);
	}

	
}

void Enemy::Respawn()
{
	X = 40;
	HP = 50;
	Sleep(1000);
	system("cls");
}

void Enemy::KingRespawn()
{
	X = 40;
	HP = 100;
	Sleep(1000);
	system("cls");
}

	


//void Enemy::Move(Player& player)
//{
//	while (X > 26)
//	{
//		ChangeImage(SlimeMove);
//		ShowImage();	
//		Sleep(100);
//		ChangeImage(SlimeIdle);
//		ShowImage();	
//		Sleep(100);
//
//		X--;
//	}
//	Sleep(500);
//	Battle(player);
//}

