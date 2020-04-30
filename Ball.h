#ifndef BALL_HPP
#define BALL_HPP

#include "Paddle.h"


class Ball : public sf::CircleShape
{
	public:
		
		Ball(float rad, sf::Color col, sf::Vector2f pos, const std::shared_ptr<Paddle> pad1, const std::shared_ptr<Paddle> pad2);
		void Init();
		void Update(sf::RenderWindow &pWindow, sf::Time elapsed);
	
	protected:
		int direction;
		float speed;
		sf::Vector2f movement;

		std::shared_ptr<Paddle> pPad1;
		std::shared_ptr<Paddle> pPad2;
		
		sf::SoundBuffer sbPing;
		sf::SoundBuffer sbPong;
		sf::Sound sndPing;
		sf::Sound sndPong;
		sf::Texture textur;

};

#endif // !BALL_HPP
