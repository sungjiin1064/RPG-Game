#pragma once

#include "Console.h"
#include "Common.h"
#include "ImageModel.h"
#include <vector>

enum CharacterState
{
	IDLE, MOVE, BATTLE
};

class Character
{
public:
	int X, Y, ATK, HP;
	std::string NAME;
	std::vector<std::string> IMAGE;

	Character(int posX, int posY, int attack, int hp, std::string name, const char* model)
		: X(posX), Y(posY), ATK(attack), HP(hp), NAME(name)
	{
		IMAGE = ParseImage(model);
	}

	std::vector<std::string> ParseImage(const char* model)
	{
		std::vector<std::string> parsedImage;
		const char* lineStart = model;

		while (*lineStart)
		{
			const char* lineEnd = strchr(lineStart, '\n');
			if (!lineEnd)
				lineEnd = model + strlen(model);

			parsedImage.emplace_back(lineStart, lineEnd - lineStart);
			lineStart = (*lineEnd) ? lineEnd + 1 : lineEnd;
		}

		return parsedImage;
	}

	void ShowImage(const std::vector<std::string>& image)
	{
		for (size_t i = 0; i < image.size();i++)
		{
			Console::GoToXY(X, Y + static_cast<int>(i));
			cout << image[i] << endl;
		}
	}


	void ChangeImage(ImageModel& model, CharacterState state)
	{
		std::vector<std::string> newImage;

		switch (state)
		{
		case IDLE:
			newImage = ParseImage(model.SwordIdle);
			break;
		case MOVE:
			newImage = ParseImage(model.SwordMove);
			break;
		case BATTLE:
			newImage = ParseImage(model.SwordIdle);
			break;

		}
	}
};

//class Character
//{
//public:
//	int X;
//	int Y;
//	int ATK;
//	int HP;
//	string NAME;
//	std::vector<std::string> IMAGE{};
//
//public:
//	Character(int posX, int posY, int attack, int hp, string name, const char* model)
//		: X(posX), Y(posY), ATK(attack), HP(hp), NAME(name)
//	{
//		const char* lineStart = model;
//
//		while (*lineStart)
//		{
//			const char* lineEnd = strchr(lineStart, '\n');
//			if (!lineEnd)
//				lineEnd = model + strlen(model);
//
//			IMAGE.emplace_back(lineStart, lineEnd - lineStart);
//			lineStart = (*lineEnd) ? lineEnd + 1 : lineEnd;
//		}
//	}
//};

//void ShowImage()
//{
///*	for (int i = 0;i < IMAGE.size();i++)
//	{
//		Console::GoToXY(X, Y + i);
//		cout << IMAGE[i]<<endl;
//	}*/

//	for (size_t i = 0;i < IMAGE.size();i++)
//	{
//		Console::GoToXY(X, Y + i);
//		cout << IMAGE[i] << endl;
//	}
//}