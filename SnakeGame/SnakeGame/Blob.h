#pragma once
#include "SFML/Graphics.hpp"

class Blob {
public:
	explicit Blob(const sf::Vector2f _position) : m_position(_position) {};

	void Render(sf::RenderWindow& _window);

	sf::Vector2f m_position;
	float m_radius{ 40.f };

};

