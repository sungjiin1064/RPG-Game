
#include "Console.h"
#include "ImageModel.h"
#include "Common.h"
#include "Player.h"
#include "Monster.h"


int main()
{
	Console::CursorVisible(false);

	ImageModel model;

	Player Sword = { 15,17,11,1000,"�ٹٸ���", model.SwordIdle };
	Monster Slime = { 43,17,6,50,"������",model.SlimeIdle };
	Monster KingSlime = { 43,17,60,500,"ŷ������",model.KingSlimeIdle };

	

	Console::GoToXY(0,0);	
	cout << model.backGround << endl;
	
	
	
	

	while (true)
	{
		Console::GoToXY(0, 0);
		cout << model.backGround << endl;
		
		Sword.ShowImage();
		Slime.ShowImage();
		Slime.Move(model);
		system("cls");
	}
	
}