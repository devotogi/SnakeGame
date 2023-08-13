#pragma once
#include "Types.h"
class BlockSnake : public GameObject 
{
public:
				BlockSnake() {};
				BlockSnake(Pos& pos);
				virtual ~BlockSnake();

public:
	void		Init();
	void		Update(char key);
	void		Render();
	void		Move();
	void		AddBlock(Block* block);
	bool		isDead();
	Block*		GetHeader();
	void		SetMapSize(int mapSize);
	void		EatFood();

private:
	Block*		_header;
	Block*		_tail;
	int			_dir;
	bool		_isDead;
	MOVE		_move;
	char		_key;
	int			_mapSize;

};

