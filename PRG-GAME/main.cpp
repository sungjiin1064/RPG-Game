
#include "Console.h"
#include "ImageModel.h"
#include "Image.h"
#include <iostream>

using namespace std;

int main()
{
	Console::CursorVisible(false);

	ImageModel model;

	Console::GoToXY(0,-1);	
	cout << model.backGround << endl;

	Image image(model.SwordIdle);
	image.show(0,0);


	while (true);
	
}