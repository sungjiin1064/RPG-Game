
#include "Player.h"
#include "Enemy.h"

int main()
{
	Player Sword = { 10,10,11,100,"�ٹٸ���",SwordIdle };
	Player Arrow = { 10,10,11,100,"�Ƹ���",ArrowIdle };
	Enemy Slime = { 40,10,6,50,"������",SlimeIdle };
	Enemy KingSlime = { 40,10,60,500,"ŷ������",KingSlimeIdle };
	
	while (true)
	{
		Sword.ShowImage();
		Slime.ShowImage();
		
		Slime.Move(Sword);
	
		

		
	}
}