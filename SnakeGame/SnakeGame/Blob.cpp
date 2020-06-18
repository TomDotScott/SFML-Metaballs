#include "Blob.h"

void Blob::Update()
{
	m_position += m_velocity;

	if(m_position.x > utilities::k_width || m_position.x < 0)
	{
		m_velocity.x *= -1;
	}
	if (m_position.y > utilities::k_height || m_position.y < 0) {
		m_velocity.y *= -1;
	}
}

void Blob::Render(sf::RenderWindow& _window)
{
	sf::CircleShape shape(m_radius);
	shape.setOrigin(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2);
	shape.setPosition(m_position);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(3.f);
	shape.setFillColor({ 0, 0, 0, 0 });
	
	_window.draw(shape);	
}
