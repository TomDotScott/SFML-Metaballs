#include "Blob.h"

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
