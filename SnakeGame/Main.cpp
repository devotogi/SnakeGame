#include "Types.h"
#include "GameManager.h"
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	GameManager gameManger;
	gameManger.Init();
	while (true)
	{
		char key = 0;
		if (_kbhit()) key = _getch();

		gameManger.Update(key);

		gameManger.Render();

	}
	return 0;
}