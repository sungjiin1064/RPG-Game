#include "Respawn.h"
#include "Character.h"

void respawn()
{
	slime.x = 20;
	slime.health = 3;
}

void KingRespawn()
{
	setCursorPos(player.x + 7, player.y - 9);
	printf("킹슬리임 등장\n");
	Slime.x = 60;
	Slime.health = 200;
}
