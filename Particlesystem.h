#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <SFML/Graphics.hpp>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

	ParticleSystem() :
		m_particles(5000),
		m_vertices(sf::Points, 5000),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0)
	{
	}
	ParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(sf::Points, count),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0)
	{
	}

	void setEmitter(sf::Vector2f position);
	void update(sf::Time elapsed);

private:
	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time lifetime;
	};

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void resetParticle(std::size_t index);

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
};

#endif // !PARTICLESYSTEM_HPP