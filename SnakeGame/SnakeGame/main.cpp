#include <iostream>
#include <SFML/Graphics.hpp>
#include "Blob.h"
#include "Utilities.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(utilities::k_width, utilities::k_height), "Metaballs");
	std::vector<Blob> blobs;

	for (int i = 0; i < utilities::k_blobAmount; ++i) {
		Blob b({ static_cast<float>(utilities::random_range(0, utilities::k_width)), static_cast<float>(utilities::random_range(0, utilities::k_height)) });
		blobs.push_back(b);
	}


	// Create an instance of the SFML CircleShape and initialise it so radius is 100
	sf::RectangleShape shape({ 1, 1 });

	// Set the shape's fill colour attribute to Green
	shape.setFillColor(sf::Color::Green);

	// Main loop that continues until we call window.close()
	while (window.isOpen()) {
		// Handle any pending SFML events
		// These cover keyboard, mouse,joystick etc.
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		// We must clear the window each time around the loop
		window.clear(sf::Color::White);

		for (int x = 0; x < utilities::k_width; x++) {
			for (int y = 0; y < utilities::k_height; y++) {
				shape.setPosition(static_cast<float>(x), static_cast<float>(y));
				// work out colour based on the sum of the distances between the blobs 
				float sum{0.f};
				for (auto blob : blobs) {
					// work out the distance between the points and the centre
					auto d = std::hypot((blob.m_position.x - x), (blob.m_position.y - y));
					
					// Colour is inversely proportionate to the distance 
					sum += static_cast<int>((100 * blob.m_radius / d));
					
				}
				if (sum > 255) {
					sum = 255;
				}
				shape.setFillColor({ static_cast<uint8_t>(sum), 255, 255 });

				window.draw(shape);

			}
		}

		for (auto& b : blobs) {
			//b.Render(window);
			b.Update();
		}


		// Get the window to display its contents
		window.display();
	}


	return 0;
}
