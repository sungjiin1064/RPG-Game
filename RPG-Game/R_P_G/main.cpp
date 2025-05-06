
#include "Player.h"
#include "Enemy.h"

int main()
{
	Player Sword = { 10,10,11,100,"바바리안",SwordIdle };
	Player Arrow = { 10,10,11,100,"아마존",ArrowIdle };
	Enemy Slime = { 40,10,6,50,"슬라임",SlimeIdle };
	Enemy KingSlime = { 40,10,60,500,"킹슬라임",KingSlimeIdle };
	
	while (true)
	{
		Sword.ShowImage();
		Slime.ShowImage();
		
		Slime.Move(Sword);
	
		

		
	}
}