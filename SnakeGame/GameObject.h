#pragma once
#include "Types.h"

class GameObject
{
public:
					GameObject(Pos& pos) : _pos(pos) {};
					GameObject() {};
	virtual			~GameObject() {};
public:
	virtual void	Init() = 0;
	virtual void	Update(char key) = 0;
	virtual void	Render() = 0;

	Pos				GetPos();
protected:
	Pos				_pos;
};



class Block
{
public:
					Block() {};
					Block(Pos& pos) : _pos(pos) {};
					~Block() {};
public:
	Block*			_next;
	Block*			_prev;

	Pos				GetPos();
	void			SetPos(Pos pos);
protected:
	Pos				_pos;
};