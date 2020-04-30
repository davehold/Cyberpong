#include "Playstate.h"

Playstate::Playstate() 
{
	upPad1 = std::make_shared<Paddle>(sf::Vector2f(53.f, 192.f), sf::Color::Blue, sf::Vector2f(30.f, 310.f), "assets\\gfx\\BLUE\\sheet2.png");
	upPad2 = std::make_shared<Paddle>(sf::Vector2f(53.f, 192.f), sf::Color::Red, sf::Vector2f((float) 1250.f, 310.f), "assets\\gfx\\RED\\sheet2.png");
	upBall = std::unique_ptr<Ball>(new Ball(20.f, sf::Color::Magenta, sf::Vector2f(640, 310), upPad1, upPad2));
	
	particles = ParticleSystem(5000);

	tBackground.loadFromFile("assets\\gfx\\background2.png");
	font.loadFromFile("assets\\fnt\\BRLNSR.ttf");
	sbPoint.loadFromFile("assets\\snd\\point.wav");

	music.openFromFile("assets\\snd\\loop.ogg");
	music.setVolume(25.f);
	music.setLoop(true);
	music.play();
	sndPoint.setBuffer(sbPoint);

	txtPointsLeft.setFont(font);
	txtPointsLeft.setCharacterSize(50);
	txtPointsLeft.setString("0");
	txtPointsLeft.setPosition(500.f, 10.f);

	txtPointsRight.setFont(font);
	txtPointsRight.setCharacterSize(50);
	txtPointsRight.setString("0");
	txtPointsRight.setPosition(700.f, 10.f);

	upPad1->setKeyUp(sf::Keyboard::W);
	upPad1->setKeyDown(sf::Keyboard::S);
	upPad2->setKeyUp(sf::Keyboard::Up);
	upPad2->setKeyDown(sf::Keyboard::Down);

	tBackground.setSmooth(true);
	sBackground.setTexture(tBackground);

	pointsLeft = 0;
	pointsRight = 0;

}

void Playstate::HandleEvents(Game& game)
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

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Key::F1)
			{
				music.stop();
				
				game.ChangeState(Game::MAINMENU);
			}

			if (event.key.code == sf::Keyboard::Key::Space)
			{
				upBall->Init();	
			}
		}
	}
}

void Playstate::Update(Game& game)
{
	upBall->Update(game.mWindow, game.frameDeltaTime);
	upPad1->Update(game.mWindow, game.frameDeltaTime);
	upPad2->Update(game.mWindow, game.frameDeltaTime);

	particles.setEmitter(
				sf::Vector2f(
							upBall->getPosition().x + upBall->getRadius() / 2, 
							upBall->getPosition().y + upBall->getRadius() / 2
							)
						);
	particles.update(game.frameDeltaTime);
	
	// set point
	if(upBall->getPosition().x <= 0)
	{
		pointsRight++;
		sndPoint.play();
		upBall->Init();		
		upPad1->Init();
		upPad2->Init();
	} else if (upBall->getPosition().x >= 1280)
	{
		pointsLeft++;
		sndPoint.play();
		upBall->Init();
		upPad1->Init();
		upPad2->Init();
	}

	txtPointsLeft.setString(game.NumberToString(pointsLeft));
	txtPointsRight.setString(game.NumberToString(pointsRight));
}

void Playstate::Draw(Game& game)
{
	game.mWindow.draw(sBackground);
	game.mWindow.draw(particles);
	game.mWindow.draw(*upBall);
	game.mWindow.draw(*upPad1);
	game.mWindow.draw(*upPad2);
	game.mWindow.draw(txtPointsLeft);
	game.mWindow.draw(txtPointsRight);
}

Playstate::~Playstate()
{
	std::cout << "Playstate-Konstruktor wurde aufgerufen" << std::endl;
}