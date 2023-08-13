#include "BlockSnake.h"
#include "GameManager.h"
// ���� �� ���� 2��¥�� �� �����
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
// Ű�� �Է¹޾����� ��ǥ�� ������Ʈ ���ִ� �Լ�
void BlockSnake::Update(char key)
{
	_key = key;

	int dx[] = { 0, 1, 0, -1, 0, 0 };
	int dy[] = { -1, 0, +1, 0, 0, 0 };
	// �Ӹ��� ���뿡 ������ �ױ⶧���� ���� �����ִ� ���⿡�� �ݴ�������� �̵��� ����
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

			// ���� �Ӹ��� ���뿡 ������� ���
			if (now != nullptr && now->GetPos() == headerPos)
				_isDead = true;
		}
	}

	Pos headPos = _header->GetPos();

	// �� ��ǥ�� �Ӹ� ��ǥ�� ������ ���
	if (headPos._x == 0 || headPos._x == _mapSize - 1 || headPos._y == 0 || headPos._y == _mapSize - 1)
		_isDead = true;
}

void BlockSnake::Render()
{

}

void BlockSnake::Move()
{

}

// �� �ڿ� ���� �ִ� ��å
// ���� �������� ���������� �Ʒ��� ���� ����
// �Ʒ� �������� ���������� ���� ���� ����
// ���� �������� ���������� �����ʿ� ���� ����
// ������ �������� ���������� ���ʿ� ���� ����
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
// ���̸� �Ծ����� ����
void BlockSnake::EatFood()
{
	Block* appendBlock = new Block;
	AddBlock(appendBlock);
	GameManager::AddPoint();
}
