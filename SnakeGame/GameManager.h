#pragma once
#include "Types.h"
class BoardMap;

class GameManager
{
public:
	bool		_gameOver;
public:
	void		Init();
	void		Update(char key);
	void		Render();
	static int	GetPoint();
	static void	AddPoint();
	static void InitPoint();
public:
	BoardMap*	_boardMap;
};
static int		s_point = 0;