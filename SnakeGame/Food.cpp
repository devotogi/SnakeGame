#include "Food.h"

Food::Food()
{
	Init();
}

Food::Food(int mapSize) : _mapSize(mapSize) 
{
	Init();
};


void Food::Init()
{
	_pos._x = 10;
	_pos._y = 10;
}

void Food::Update(char key)
{
	_pos._x = (rand() % (_mapSize - 1)) + 1;
	_pos._y = (rand() % (_mapSize - 1)) + 1;
}


void Food::Update(TileType** maps)
{
	while (maps[_pos._y][_pos._x] != TileType::EMPTY)
	{
		_pos._x = (rand() % (_mapSize - 1)) + 1;
		_pos._y = (rand() % (_mapSize - 1)) + 1;
	}
}

void Food::Render()
{

}

void Food::SetMapSize(int mapSize)
{
	_mapSize = mapSize;
}
