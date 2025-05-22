#pragma once

#include <Windows.h>

class Console
{
public:
	static void GoToXY(int x, int y)
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static void CursorVisible(bool show)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorinfo;
		GetConsoleCursorInfo(hConsole, &cursorinfo);
		cursorinfo.bVisible = show;
		SetConsoleCursorInfo(hConsole, &cursorinfo);
	}
};