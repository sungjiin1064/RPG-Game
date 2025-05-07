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
	
	void BossLoding();
	
	void GoldDrop();
	
	void ShowGold();
	
};
