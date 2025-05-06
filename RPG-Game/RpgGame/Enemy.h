#pragma once

#include "Character.h"
#include "Player.h"

class Enemy : Character
{
public:


public:
	Enemy(int posX, int posY, int attack, int hp, string name, char image[UNIT_HEIGHT][UNIT_WIDTH + 1])
		: Character(posX, posY, attack, hp, name, image) {}

	void Move(Player* player);
	void ShowImage();
	void ChangeImage(char image[UNIT_HEIGHT][UNIT_WIDTH + 1]);

	void SetBattle(char image[UNIT_HEIGHT][UNIT_WIDTH + 1],Player* player);

	void Battle(Player* player, Enemy enemy);
	

};