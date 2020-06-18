#pragma once
#include "SFML/Graphics.hpp"
#include "Utilities.h"

class Blob {
public:
	explicit Blob(const sf::Vector2f _position) : m_position(_position)
	{
		m_radius = utilities::random_range(4, 40);
		m_velocity.x = utilities::random_range(1, 10);
		m_velocity.y = utilities::random_range(1, 10);
	};

	void Update();
	
	void Render(sf::RenderWindow& _window);

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	
	float m_radius;	
};

