#pragma once
class ConsoleHelper
{
public:
	static void GotoXY(int x, int y);
	static void GotoXY(struct Pos& pos);
	static void Clear();
	static void ShowConsoleCursor(bool showFlag);
};
