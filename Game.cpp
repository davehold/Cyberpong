#include "Game.h"

Game::Game()
: mWindow(sf::VideoMode(1280, 720), "CyberPong", sf::Style::Close)
{
	running = true;
	hasFocus = true;
}

Game::~Game()
{
	running = false;
	std::cout << "DESTRUKTION" << std::endl;
}

void Game::Run()
{
	while (mWindow.isOpen())
	{
		now = clock.getElapsedTime();
		frameDeltaTime = (now - then);// / 1000.f;
		then = now;

		CurrentState->HandleEvents(*this);

		if(hasFocus)
		{
			mWindow.clear(sf::Color(0, 134, 196));
			CurrentState->Update(*this);
			CurrentState->Draw(*this);
		}		

		mWindow.display();
	}
}

bool Game::isRunning()
{
	return running; 
}

void Game::ChangeState(gameStates newState)
{
	switch (newState)
	{
		case MAINMENU:
			CurrentState = std::move(std::unique_ptr<MainMenuState>(new MainMenuState));
		break;

		case PLAY:
			CurrentState = std::move(std::unique_ptr<Playstate>(new Playstate));
		break;
	}
}

std::string Game::NumberToString(int num)
{
	std::ostringstream ss;
	ss << num;
	return ss.str();
}