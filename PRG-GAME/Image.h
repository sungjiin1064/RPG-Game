#pragma once

#define UNIT_WIDTH 11
#define UNIT_HEIGHT 5

#include <iostream>
#include <string>
#include "Console.h"

using namespace std;

class Image
{
private:
	char art[UNIT_HEIGHT][UNIT_WIDTH + 1];
	int _height = 5;

public:
	Image(const char* model)
	{
		
		const char* lineStart = model;
		for (int i = 0; i < height;i++)
		{
			const char* lineEnd = strchr(lineStart, '\n');
			if (lineEnd == nullptr)
			{
				lineEnd = model + strlen(model);
			}
			int length = lineEnd - lineStart;
			strncpy_s(this->art[i], lineStart, length);
			lineStart = lineEnd + 1;
		}
	}

	void show(int x, int y) const
	{
		for (int i = 0;i < _height;i++)
		{
			Console::GoToXY(x, y + i);
			cout << art[i];

		}
	}
};