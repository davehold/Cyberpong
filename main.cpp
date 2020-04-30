#include <iostream>
#include "Game.h"

//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

int main()
{
	Game Pong;
	
	Pong.ChangeState(Game::MAINMENU);
	
	while (Pong.isRunning())
	{
		Pong.Run();
	}

	return 0;
}