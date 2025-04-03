#include "Character.h"


Character player = { 10,10,550,11,"(  '' )/","(  '' )ㅡE","__+__"};
Character monster = { 60,10 };
Character slime = { 20,10,3,6," ( ''  )","( ''   )"," ( x x )"};
CharacterKing Slime =
//{ 60,10,100,12,{"   - -"," - ..  -","- - - - -"},{" - -","- ..  -","- - - - -"},{" - - - - -","'_ _x x_ _'"}};
{ 60,10,100,12," (     )","(      )"," (     )" };

void setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void startPosition()
{
	setCursorPos(player.x - 8, player.y - 2);
	printf("플레이어 체력 : %d", player.health);
	setCursorPos(player.x, player.y);
	printf("%s", player.action1);
	setCursorPos(slime.x, slime.y - 2);
	printf("슬라임 체력 : %d", slime.health);
	setCursorPos(slime.x, slime.y);
	printf("%s", slime.action1);
}
