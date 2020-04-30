#include "Ball.h"

Ball::Ball(float rad, sf::Color col, sf::Vector2f pos, const std::shared_ptr<Paddle> pad1, const std::shared_ptr<Paddle> pad2)
{
	setRadius(rad);
	setFillColor(col);
	setOrigin(getRadius() / 2, getRadius() / 2);
	setPosition(pos);

	pPad1 = pad1;
	pPad2 = pad2;

	direction	= 1;
	speed		= 0.f;
	movement	= sf::Vector2f( speed, 0.f );

	sbPing.loadFromFile("assets\\snd\\Pong_bing.wav");
	sbPong.loadFromFile("assets\\snd\\Pong_schnuzzel.wav");
	textur.loadFromFile("assets\\gfx\\ball.png");
	textur.setSmooth(true);


	sndPing.setBuffer(sbPing);
	sndPong.setBuffer(sbPong);
	setTexture(&textur);
}

void Ball::Init()
{
	speed = 500.f;

	direction = rand() % 2;

	if(direction == 0)
		movement = sf::Vector2f( speed, 0.f );
	else
		movement = sf::Vector2f( -speed, 0.f );

	setPosition( 640.f, 360.f );
}

void Ball::Update(sf::RenderWindow &pWin, sf::Time elapsed)
{
	float bX = getPosition().x;	// ball x
	float bY = getPosition().y;	// ball y
		
	sf::Vector2f p1p = pPad1->getPosition(); // paddle 1 position
	sf::Vector2f p2p = pPad2->getPosition(); // paddle 2 position

	// Fliegt der Ball gegen die Hozizontalen Grenzen?
	if (bY <= 0)
	{
		sndPing.play();
		movement.y = speed;
	}
	else if (bY >= pWin.getSize().y)
	{
		sndPing.play();
		movement.y = -speed;
	}
		
	// Fliegt der Ball gegen einen Schläger?
	// Linker Schläger
	// ball 13 offset, paddle 10 offset
	
	if (getGlobalBounds().left + 20 < p1p.x + (pPad1->getSize().x / 2) &&
		getGlobalBounds().left + 20 > p1p.x - (pPad1->getSize().x / 2) &&
		getGlobalBounds().top + getGlobalBounds().height -23 >= p1p.y - pPad1->getSize().y / 2 &&
		getGlobalBounds().top +23 <= p1p.y + pPad1->getSize().y / 2)
	{
		setFillColor(pPad1->getFillColor());

		if( speed < 0 )
		{
			speed -= 50.5f;
		} else {
			speed += 50.5f;
		}

		// oben unten oder mitte?
		if (bY < p1p.y)
		{
			sndPong.play();
			movement.x = speed;
			movement.y = -speed;
		}
		else if (bY > p1p.y)
		{
			sndPong.play();
			movement.x = speed;
			movement.y = speed;
		}
		else
		{
			sndPong.play();
			movement.x = speed;
		}		

	}
	// Rechter Schläger
	else if (getGlobalBounds().left + 20 < p2p.x + (pPad2->getSize().x / 2) &&
		getGlobalBounds().left + 20 > p2p.x - (pPad1->getSize().x / 2) &&
		getGlobalBounds().top + getGlobalBounds().height - 23 >= p2p.y - pPad2->getSize().y / 2 &&
		getGlobalBounds().top + 23 <= p2p.y + pPad2->getSize().y / 2)
	{
		setFillColor(pPad2->getFillColor());

		// oben, unten oder mitte?
		if (bY < p2p.y)
		{
			sndPong.play();
			movement.x = -speed;
			movement.y = -speed;
		}
		else if (bY > p2p.y)
		{
			sndPong.play();
			movement.x = -speed;
			movement.y = speed;
		}
		else
		{
			sndPong.play();
			movement.x = -speed;
		}
	
	}

	move(movement.x * elapsed.asSeconds(),  movement.y * elapsed.asSeconds());

	//std::cout << movement.x * elapsed.asSeconds() << std::endl;
}


