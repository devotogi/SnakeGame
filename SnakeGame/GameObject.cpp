#include "GameObject.h"

Pos GameObject::GetPos()
{
	return _pos;
}

Pos Block::GetPos()
{
	return _pos;
}

void Block::SetPos(Pos pos)
{
	_pos = pos;
}
