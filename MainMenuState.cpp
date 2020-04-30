#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
	font.loadFromFile("assets\\fnt\\BRLNSR.ttf");

	txtStartGame.setFont(font);
	txtStartGame.setString("Starte die Maschine!");
	txtStartGame.setCharacterSize(30);
	txtStartGame.setPosition(400.f, 500.f);

	txtQuitGame.setFont(font);
	txtQuitGame.setString("Fahr' die Systeme runter!");
	txtQuitGame.setCharacterSize(30);
	txtQuitGame.setPosition(400.f, 550.f);

	sbClick.loadFromFile("assets\\snd\\click2.wav");
	sbSelect.loadFromFile("assets\\snd\\select3.wav");


	music.openFromFile("assets\\snd\\track1.ogg");
	music.setVolume(25.f);
	music.play();

	sndClick.setBuffer(sbClick);
	sndSelect.setBuffer(sbSelect);

	bStartGameSelected = false;
	bQuitGameSelected = false;
}


void MainMenuState::HandleEvents(Game& game)
{
	sf::Event event;
	
	while (game.mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			music.stop();
			game.mWindow.close();
			game.running = false;
		}

		// Maustaste gedrückt
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == 0)
			{
				if (bStartGameSelected)
				{
					sndClick.play();
					music.stop();
					
					game.ChangeState(Game::PLAY);
					
				}
				else if (bQuitGameSelected)
				{
					sndClick.play();
					music.stop();
					game.mWindow.close();
					game.running = false;
				}
			}
		}

		//nur für den anfang des tutorials, danach entfernen
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Key::F1)
			{
				music.stop();
				game.ChangeState(Game::PLAY);
			}
		
		}
	}
}

void MainMenuState::Update(Game& game)
{
	if (txtStartGame.getGlobalBounds().contains(sf::Mouse::getPosition(game.mWindow).x, sf::Mouse::getPosition(game.mWindow).y) &&
		txtStartGame.getColor() != sf::Color::Green)
	{
		sndSelect.play();
		txtStartGame.setColor(sf::Color::Green);
		bStartGameSelected = true;
	}
	else if (!txtStartGame.getGlobalBounds().contains(sf::Mouse::getPosition(game.mWindow).x, sf::Mouse::getPosition(game.mWindow).y) && 
			 txtStartGame.getColor() == sf::Color::Green)
	{
		txtStartGame.setColor(sf::Color::White);
		bStartGameSelected = false;
	}

	if (txtQuitGame.getGlobalBounds().contains(sf::Mouse::getPosition(game.mWindow).x, sf::Mouse::getPosition(game.mWindow).y) &&
		txtQuitGame.getColor() != sf::Color::Green)
	{
		sndSelect.play();
		txtQuitGame.setColor(sf::Color::Green);
		bQuitGameSelected = true;
	}
	else if (!txtQuitGame.getGlobalBounds().contains(sf::Mouse::getPosition(game.mWindow).x, sf::Mouse::getPosition(game.mWindow).y) &&
		txtQuitGame.getColor() == sf::Color::Green)
	{
		txtQuitGame.setColor(sf::Color::White);
		bQuitGameSelected = false;
	}
}

void MainMenuState::Draw(Game& game)
{
	game.mWindow.draw(txtStartGame);
	game.mWindow.draw(txtQuitGame);
}

MainMenuState::~MainMenuState()
{
	std::cout << "menudestruktor wurde aufgerufe" << std::endl;
}