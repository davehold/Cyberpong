#include "Paddle.h"

Paddle::Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos, sf::String texture)
{
	textur.loadFromFile(texture);

	std::cout << "neu" << std::endl;
	setSize(rect);
	//setFillColor(col);
	setOrigin(getSize().x / 2, getSize().y / 2);
	setPosition(pos);

	textur.setSmooth(true);
	setTexture(&textur, true);
	setTextureRect(sf::IntRect(0, 0, 53, 192));
		
	//Up = sf::Keyboard::Key:;
	//Down = sf::Keyboard::Key;
	initPos = pos;
	speed = 500.f;

	frame = 0;
	frames = 20;
	frameWidth = 53;
}

void Paddle::Init()
{
	setPosition(initPos);
}

void Paddle::setKeyUp(sf::Keyboard::Key k)
{
	Up = k;
}

void Paddle::setKeyDown(sf::Keyboard::Key k)
{
	Down = k;
}

void Paddle::Update(sf::RenderWindow &pWin, sf::Time elapsed)
{

	tempElapsedTime += elapsed;

	if (tempElapsedTime.asSeconds() >= .05)
	{
		if (frame < frames-1)
		{
			frame++;
		}
		else 
		{
			frame = 0;
		}

		tempElapsedTime = tempElapsedTime.Zero;
		// left top width height
		setTextureRect(sf::IntRect(frameWidth * frame, 0, frameWidth, 196));
	}

	if (sf::Keyboard::isKeyPressed(Up) && getPosition().y > getGlobalBounds().height/2)
	{
		move(sf::Vector2f(0.f, -speed * elapsed.asSeconds()));
	}
	else if (sf::Keyboard::isKeyPressed(Down) && getPosition().y < (pWin.getSize().y - getGlobalBounds().height/2))
	{
		move(sf::Vector2f(0.f, speed * elapsed.asSeconds()));
	}
}