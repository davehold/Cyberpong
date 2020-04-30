#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gamestate.h"
#include "Playstate.h"
#include "MainMenuState.h"

class Game
{
	public:

		Game();
		~Game();

		enum gameStates { MAINMENU, PLAY };

		void Run();
		void ChangeState(gameStates newState);
		bool isRunning();
		std::string NumberToString(int num);

		sf::RenderWindow mWindow;
		bool running;
		bool hasFocus;
		
		sf::Clock clock;
		sf::Time then = clock.getElapsedTime();
		sf::Time now;
		sf::Time frameDeltaTime;
		
		
	private:
		std::unique_ptr<Gamestate> CurrentState;

};

#endif // !GAME_HPP
