//#pragma once
//
//#define UNIT_WIDTH 11
//#define UNIT_HEIGHT 6
//
//#include <iostream>
//#include <string>
//#include "Console.h"
//
//#include <cstddef>
//
//using namespace std;
//
//class Image
//{
//private:
//	char art[UNIT_HEIGHT][UNIT_WIDTH + 1] = {};
//	int _height;
//
//public:
//	Image(const char* model)
//	{
//		_height = 0;
//		const char* lineStart = model;
//		
//		while (*lineStart && _height < UNIT_HEIGHT)
//		{
//			const char* lineEnd = strchr(lineStart, '\n');
//			if (!lineEnd)
//				lineEnd = model + strlen(model);
//
//			ptrdiff_t length = lineEnd - lineStart;
//			strncpy_s(this->art[_height], sizeof(this->art[_height]), lineStart, length);
//			this->art[_height][length] = '\0';
//
//			_height++;
//			lineStart = (*lineEnd) ? lineEnd + 1 : lineEnd;
//		}
//		
//	}
//
//	void show(int x, int y)
//	{
//		for (int i = 0;i < _height;i++)
//		{
//			Console::GoToXY(x, y + i);
//			cout << art[i];
//
//			
//		}
//	}
//	
//	void move()
//	{
//
//	}
//	
//};