#pragma once

#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
public:
	bool isKingSlime = false;
	int gold = 0;
	int totalGold;
	
public:
	Enemy(int posX, int posY, int attack, int hp, string name, char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
		: Character(posX, posY, attack, hp, name, image) {
	}

public:
	void ShowImage();

	void Move(Player& player);
	
	void Battle(Player& player);
	
	void Respawn();
	void KingRespawn();
	
	void BossLoding()
	{
		GoToXY(10, 2);
		cout << "����� ������ �����մϴ�.....3" << endl;
		Sleep(1000);
		GoToXY(10, 2);
		cout << "����� ������ �����մϴ�...  2" << endl;
		Sleep(1000);
		GoToXY(10, 2);
		cout << "����� ������ �����մϴ�.    1" << endl;	
		
	}

	void GoldDrop()
	{
		gold = rand() % 50 + 51;
		totalGold += gold;
	}

	void ShowGold()
	{
		GoToXY(54, 2);
		cout << "���� �����ݾ� : " << totalGold;
	}
};
