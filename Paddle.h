#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>

class Paddle : public sf::RectangleShape
{
	public:
		Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos, sf::String texture);
		void Update(sf::RenderWindow &pWindow, sf::Time elapsed);
		void Init();
		void setKeyUp(sf::Keyboard::Key k);
		void setKeyDown(sf::Keyboard::Key k);

	private:
		sf::Keyboard::Key Up;
		sf::Keyboard::Key Down;
		sf::Vector2f initPos;
		sf::Texture textur;

		float speed;
		sf::Time tempElapsedTime;
		int frame;
		int frames;
		int frameWidth;
};

#endif // !PADDLE_HPP
