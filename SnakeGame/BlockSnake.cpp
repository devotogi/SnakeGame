#include "BlockSnake.h"
#include "GameManager.h"
// 최초 뱀 생성 2개짜리 블럭 만들기
BlockSnake::BlockSnake(Pos& pos)
{
	_dir = DIR::DIR_NONE;
	_isDead = false;
	_header = new Block(pos);
	_header->_next = _tail;
	_tail = _header;
	_tail->_prev = _header;

	Block* middle = new Block;
	AddBlock(middle);
}

BlockSnake::~BlockSnake()
{
	Block* now = _header;

	while (now != nullptr)
	{
		Block* next = now->_next;
		delete now;
		now = next;
	}
}

void BlockSnake::Init()
{
}
// 키를 입력받았을때 좌표를 업데이트 해주는 함수
void BlockSnake::Update(char key)
{
	_key = key;

	int dx[] = { 0, 1, 0, -1, 0, 0 };
	int dy[] = { -1, 0, +1, 0, 0, 0 };
	// 머리가 몸통에 닿으면 죽기때문에 현재 가고있는 방향에서 반대방향으로 이동은 막음
	switch (_key)
	{
	case MOVE::MOVE_UP:
		_dir = _dir == DIR::DIR_DOWN ? DIR::DIR_DOWN : DIR::DIR_UP;
		break;

	case MOVE::MOVE_RIGHT:
		_dir = _dir == DIR::DIR_LEFT ? DIR::DIR_LEFT : DIR::DIR_RIGHT;
		break;

	case MOVE::MOVE_DOWN:
		_dir = _dir == DIR::DIR_UP ? DIR::DIR_UP : DIR::DIR_DOWN;
		break;

	case MOVE::MOVE_LEFT:
		_dir = _dir == DIR::DIR_RIGHT ? DIR::DIR_RIGHT : DIR::DIR_LEFT;
		break;
	}

	Pos headerPos = _header->GetPos();
	Pos oldPos = _header->GetPos();
	Pos newPos = oldPos + Pos{ dx[_dir], dy[_dir] };

	if (oldPos != newPos)
	{
		Block* now = _header;
		while (now != nullptr)
		{
			oldPos = now->GetPos();
			now->SetPos(newPos);
			now = now->_next;
			newPos = oldPos;

			// 뱀의 머리가 몸통에 닿았을때 사망
			if (now != nullptr && now->GetPos() == headerPos)
				_isDead = true;
		}
	}

	Pos headPos = _header->GetPos();

	// 벽 좌표에 머리 좌표가 같으면 사망
	if (headPos._x == 0 || headPos._x == _mapSize - 1 || headPos._y == 0 || headPos._y == _mapSize - 1)
		_isDead = true;
}

void BlockSnake::Render()
{

}

void BlockSnake::Move()
{

}

// 뱀 뒤에 블럭을 넣는 정책
// 위의 방향으로 가고있으면 아래에 블럭이 생김
// 아래 방향으로 가고있으면 위에 블럭이 생김
// 왼쪽 방향으로 가고있으면 오른쪽에 블럭이 생김
// 오른쪽 방향으로 가고있으면 왼쪽에 블럭이 생김
void BlockSnake::AddBlock(Block* block)
{
	Block* prev = _tail;
	Pos tailPos = prev->GetPos();
		
	switch (_dir)
	{
	case DIR::DIR_UP:
		tailPos._y = tailPos._y + 1;
		break;
	case DIR::DIR_RIGHT:
		tailPos._x = tailPos._x - 1;
		break;
	case DIR::DIR_DOWN:
		tailPos._y = tailPos._y - 1;
		break;
	case DIR::DIR_LEFT:
		tailPos._x = tailPos._x + 1;
		break;
	case DIR::DIR_NONE:
		tailPos._x = tailPos._x - 1;
		break;
	}

	block->SetPos(tailPos);
	prev->_next = block;
	block->_prev = prev;
	_tail = block;
}

bool BlockSnake::isDead()
{
	return _isDead;
}

Block* BlockSnake::GetHeader()
{
	return _header;
}

void BlockSnake::SetMapSize(int mapSize)
{
	_mapSize = mapSize;
}
// 먹이를 먹었을때 동작
void BlockSnake::EatFood()
{
	Block* appendBlock = new Block;
	AddBlock(appendBlock);
	GameManager::AddPoint();
}
