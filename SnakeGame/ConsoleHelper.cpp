#include "ConsoleHelper.h"
#include "Types.h"



void ConsoleHelper::GotoXY(int x, int y)
{
	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ConsoleHelper::GotoXY(Pos& pos)
{
	COORD cops = { pos._x, pos._y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cops);
}

void ConsoleHelper::Clear()
{
	system("cls");
}


void ConsoleHelper::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}