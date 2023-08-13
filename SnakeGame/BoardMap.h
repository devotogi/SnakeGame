#pragma once
#include "Types.h"
class BlockSnake;
class Food;

class BoardMap : public GameObject
{
public:
					BoardMap() {};
					BoardMap(int mapSize);
					virtual ~BoardMap();
public:
	void			Init();
	void			Update(char key);
	void			Render();
	const char*		TileRendering(TileType type);
	void			RefreshSnake(bool flag);
	void			RefreshFood(bool flag);
	void			ContinueMsg();
private:
	int				_mapSIze;
	TileType**		_maps;
	BlockSnake*		_snake;
	Food*			_food;
};

