#include "GameManager.h"
#include "Types.h"
#include "BlockSnake.h"
#include "BoardMap.h"

void GameManager::Init()
{
	ConsoleHelper::ShowConsoleCursor(false);
	_gameOver = false;
	_boardMap = new BoardMap(25);
}

void GameManager::Update(char key)
{
	_boardMap->Update(key);
}

void GameManager::Render()
{
	_boardMap->Render();
}

int GameManager::GetPoint()
{
	return s_point;
}

void GameManager::AddPoint()
{
	s_point += 10;
}

void GameManager::InitPoint()
{
	s_point = 0;
}
