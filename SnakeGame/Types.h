#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "ConsoleHelper.h"
struct Pos
{
	int _x;
	int _y;

	Pos operator+(const Pos& pos) 
	{
		Pos ret;
		ret._x = _x + pos._x;
		ret._y = _y + pos._y;
		return ret;
	}


	Pos operator-(const Pos& pos)
	{
		Pos ret;
		ret._x = _x - pos._x;
		ret._y = _y - pos._y;
		return ret;
	}



	Pos operator+(const int& other)
	{
		Pos ret;
		ret._x = _x + other;
		ret._y = _y + other;
		return ret;
	}

	Pos operator-(const int& other)
	{
		Pos ret;
		ret._x = _x - other;
		ret._y = _y - other;
		return ret;
	}

	bool operator==(const Pos& pos)
	{
		return (_x == pos._x) && (_y == pos._y);
	}

	bool operator!=(const Pos& pos)
	{
		return !( *this == pos);
	}
};


enum DIR
{
	DIR_UP = 0,
	DIR_RIGHT = 1,
	DIR_DOWN = 2,
	DIR_LEFT = 3,
	DIR_COUNT = 4,
	DIR_NONE = 5
};


enum MOVE
{
	MOVE_UP = 'w',
	MOVE_RIGHT = 'd',
	MOVE_DOWN = 's',
	MOVE_LEFT = 'a',
};

enum TileType 
{
	WALL = 0,
	EMPTY = 1,
	SNAKE = 2,
	FOOD = 3
};

#include "GameObject.h"