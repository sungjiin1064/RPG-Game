
#include "Console.h"
#include "ImageModel.h"
#include "Common.h"
#include "Player.h"
#include "Monster.h"


int main()
{
	Console::CursorVisible(false);

	ImageModel model;

	Player Sword = { 15,17,11,1000,"바바리안", model.SwordIdle };
	Monster Slime = { 43,17,6,50,"슬라임",model.SlimeIdle };
	Monster KingSlime = { 43,17,60,500,"킹슬라임",model.KingSlimeIdle };

	

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