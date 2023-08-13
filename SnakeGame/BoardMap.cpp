#include "BoardMap.h"
#include "BlockSnake.h"
#include "Food.h"
#include "GameManager.h"

BoardMap::BoardMap(int mapSize) : _mapSIze(mapSize)
{
	_maps = new TileType*[_mapSIze];

	for (int row = 0; row < _mapSIze; row++)
		_maps[row] = new TileType[_mapSIze];

	Init();
}

BoardMap::~BoardMap() 
{
	for (int row = 0; row < _mapSIze; row++)
		delete[] _maps[row];

	delete[] _maps;
	_maps = nullptr;

	if (_snake)
	{
		delete _snake;
		_snake = nullptr;
	}

	if (_food)
	{
		delete _food;
		_food = nullptr;
	}
		
}

void BoardMap::Init()
{
	for (int y = 0; y < _mapSIze; y++)
	{
		for (int x = 0; x < _mapSIze; x++)
		{
			// ���� �׵θ� ���� ������ ���Ѵ�
			if (x == 0 || y == 0 || x == _mapSIze - 1 || y == _mapSIze - 1)
				_maps[y][x] = TileType::WALL;

			// ���� �׵θ��� �ƴѰ��� ���(�̵��� �� ����)
			else
				_maps[y][x] = TileType::EMPTY;
		}
	}

	// ���� �ʱ���ǥ ����
	Pos snakeInitPos{ 20, 20 };

	_snake = new BlockSnake(snakeInitPos);
	_snake->SetMapSize(_mapSIze);
	_food = new Food(_mapSIze);
}

void BoardMap::Update(char key)
{
	// �� ����
	RefreshSnake(false);
	_snake->Update(key);
	RefreshSnake(true);

	// ���� ����
	RefreshFood(true);

	// ���̸� �Ծ����� Ȯ��
	Pos snakeHeadPos = _snake->GetHeader()->GetPos();
	if (snakeHeadPos == _food->GetPos())
	{
		_snake->EatFood();
		_food->Update(_maps);
	}

	// ���� �շ������� �����ϱ� �ٽ� ä���ֱ�
	for (int index = 0; index < _mapSIze; index++)
	{
		_maps[0][index] = TileType::WALL;
		_maps[index][0] = TileType::WALL;
		_maps[_mapSIze-1][index] = TileType::WALL;
		_maps[index][_mapSIze - 1] = TileType::WALL;
	}

	// ���� �׾����� Ȯ��
	if (_snake->isDead())
	{
		delete _snake;
		_snake = nullptr;

		delete _food;
		_food = nullptr;

		ContinueMsg();
		Init();
	}
}

void BoardMap::Render()
{
	ConsoleHelper::Clear();
	for (int y = 0; y < _mapSIze; y++)
	{
		for (int x = 0; x < _mapSIze; x++)
		{
			std::cout << TileRendering(_maps[y][x]);
		}
		std::cout << "\n";
	}

	ConsoleHelper::GotoXY(55, 0);
	std::cout << "Your Point: " << GameManager::GetPoint();

	Sleep(100);
}

const char* BoardMap::TileRendering(TileType type)
{
	switch (type)
	{
	case TileType::WALL:
		return "��";

	case TileType::EMPTY:
		return "  ";

	case TileType::SNAKE:
		return "��";

	case TileType::FOOD:
		return "��";
	}
}

// �� TICK�� ������ MAP�� �ִ� SNAKE ������ ���� OR ����
void BoardMap::RefreshSnake(bool flag)
{
	Block* now = _snake->GetHeader();

	while (now != nullptr)
	{
		Pos pos = now->GetPos();
		_maps[pos._y][pos._x] = flag ? TileType::SNAKE : TileType::EMPTY;
		Block* next = now->_next;
		now = next;
	}
}

// �� TICK�� ������ MAP�� �ִ� FOOD ������ ���� OR ����
void BoardMap::RefreshFood(bool flag)
{
	Pos foodPos = _food->GetPos();
	flag ? _maps[foodPos._y][foodPos._x] = TileType::FOOD : TileType::EMPTY;	
}

// GAME���� �����̰� �׾ ��� �ϰڳİ� ����� �޽���
void BoardMap::ContinueMsg()
{
	while (true)
	{
		ConsoleHelper::Clear();
		ConsoleHelper::GotoXY(30,15);
		std::cout << "Continue Any Key...";
		ConsoleHelper::GotoXY(30, 17);
		std::cout << "Your Point: " << GameManager::GetPoint();
		if (_kbhit)
		{
			_getch();
			break;
		}

		Sleep(100);
	}
}
