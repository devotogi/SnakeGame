#pragma once
#include "Types.h"
class Food : public GameObject
{
public:
				Food();
				Food(int mapSize);
				virtual ~Food() {};
public:
	void		Init();
	void		Update(char key);
	void		Render();
	void		SetMapSize(int mapSize);
	void		Update(TileType** maps);
private:
	int			_mapSize;
};

