#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <memory>
//#include <SFML/Graphics.hpp>
#include "Game.h"

class MainMenuState : public Gamestate
{
	public:
	 		 MainMenuState();
			 ~MainMenuState();
		void Init(Game& game);
		void HandleEvents(Game& game);
		void Update(Game& game);
		void Draw(Game& game);

	private:
		bool bStartGameSelected;
		bool bQuitGameSelected;

		sf::Font font;
		
		sf::Text txtStartGame;
		sf::Text txtQuitGame;		
		
		sf::SoundBuffer sbSelect;
		sf::SoundBuffer sbClick;
		sf::Sound sndSelect;
		sf::Sound sndClick;
		sf::Music music;
};

#endif // !MAINMENUSTATE_HPP
