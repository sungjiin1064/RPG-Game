
#define SLIME_WIDTH 15
#define SLIME_HEIGHT 4

#include <iostream>

namespace Actor
{
	struct Character
	{
		int x, y, attack, health;
		char name[20];	
		char action1[SLIME_WIDTH + 1];
		char action2[SLIME_WIDTH + 1];
		char action3[SLIME_WIDTH + 1];
		char action4[SLIME_WIDTH + 1];
	};
	struct BossCharacter
	{
		int x, y, attack, health;
		char name[20];
		char action1[SLIME_HEIGHT][SLIME_WIDTH + 1];
		char action2[SLIME_HEIGHT][SLIME_WIDTH + 1];
		char action3[SLIME_HEIGHT][SLIME_WIDTH + 1];
		char action4[SLIME_HEIGHT][SLIME_WIDTH + 1];
	};
	Character player, slime;
	BossCharacter KingSlime;
}

Actor::player = {}

int main()
{
	Actor::Character::x

	
}