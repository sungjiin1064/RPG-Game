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

	if (X < 26)
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
			Sleep(200);
			ChangeImage(KingSlimeIdle);
			ShowImage();
			Sleep(200);

			X--;
		}
		else
		{			
			ChangeImage(SlimeMove);
			ShowImage();
			Sleep(100);
			ChangeImage(SlimeIdle);
			ShowImage();			
			Sleep(300);

			X--;
		}
		
	}
}

void Enemy::Battle(Player& player) 
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
				GoldDrop();		
				ShowGold();
			}
			if(isKingSlime)
			{
				ChangeImage(KingSlimeBattle);
			}
			else
			{
				ChangeImage(SlimeBattle);
			}
			ShowImage();
			player.ChangeImage(SwordBattle);
			player.ShowImage();			

		}
		else
		{
			if (isKingSlime)
			{				
				ChangeImage(KingSlimeIdle);
			}
			else
			{
				ChangeImage(SlimeIdle);
			}
			ShowImage();
			player.ChangeImage(SwordIdle);
			player.ShowImage();
		}
		isBattleImage = !isBattleImage;
		Sleep(300);
	}

	if (HP == 0)
	{
		if (isKingSlime)
		{
			GoToXY(10, 2);
			cout << "보스를 처치하였습니다." << endl;
			Sleep(1000);
			GoToXY(10, 3);
			cout << "게임을 종료합니다...  " << endl;
			Sleep(1000);
			
			system("cls");
			GoToXY(10, 2);
			cout << "승 리" << endl;
			
			exit(0);
		}
		else if (Count < 2)
		{
			GoToXY(14, 2);
			cout << "보스 소환까지 : " << Count << " / 2" << endl;
			ChangeImage(SlimeIdle);
			ShowImage();
			player.ChangeImage(SwordIdle);
			player.ShowImage();

			Respawn();
		}
		else
		{
			ChangeImage(SlimeIdle);  // Idle 바꾸고 -> Slime.Image SlimeIdle 데이터가 들어옴       
			ShowImage();
			player.ChangeImage(SwordIdle);
			player.ShowImage();	
			
			KingRespawn();
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
		system("cls");
		GoToXY(10, 2);
		cout << "Game Over" << endl;
		Sleep(1000);
		exit(0);
	}
	
}

void Enemy::Respawn()
{
	X = 36;
	HP = 50;
	Sleep(1000);   
	system("cls");
}

void Enemy::KingRespawn()
{
	GoToXY(14, 2);
	cout <<"보스 소환까지 : " << Count << " / 2" << endl;
	Sleep(1000);

	BossLoding();
	X = 36;
	HP = 100;
	//Sleep(1000);
}

void Enemy::BossLoding()
{
	GoToXY(10, 2);
	cout << "잠시후 보스가 등장합니다.....3" << endl;
	Sleep(1000);
	GoToXY(10, 2);
	cout << "잠시후 보스가 등장합니다...  2" << endl;
	Sleep(1000);
	GoToXY(10, 2);
	cout << "잠시후 보스가 등장합니다.    1" << endl;

}

void Enemy::GoldDrop()
{
	gold = rand() % 50 + 51;
	totalGold += gold;
}

void Enemy::ShowGold()
{
	GoToXY(54, 2);
	cout << "현재 소지금액 : " << totalGold;
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

