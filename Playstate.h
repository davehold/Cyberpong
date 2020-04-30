#ifndef PLAYSTAT132
#define PLAYSTAT132

#include "Game.h"
#include "Gamestate.h"
#include "Ball.h"
#include "Paddle.h"
#include "Particlesystem.h"


class Playstate : public Gamestate
{
	public:
			 Playstate();
			 ~Playstate();
		void HandleEvents(Game& game);
		void Update(Game& game);
		void Draw(Game& game);

	private:
		std::unique_ptr<Ball> upBall;
		std::shared_ptr<Paddle> upPad1;
		std::shared_ptr<Paddle> upPad2;

		sf::Font font;
		sf::Text txtPointsLeft;
		sf::Text txtPointsRight;

		int pointsLeft;
		int pointsRight;

		sf::SoundBuffer sbPoint;
		sf::Sound sndPoint;
		sf::Music music;

		sf::Texture tBackground;
		sf::Sprite sBackground;
		
		ParticleSystem particles;
};

#endif // !Playstate_HPP
