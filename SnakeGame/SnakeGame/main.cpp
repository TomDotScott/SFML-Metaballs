#include <iostream>
#include <SFML/Graphics.hpp>
#include "Blob.h"
#include "Utilities.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(utilities::k_width, utilities::k_height), "Metaballs");



    // Create an instance of the SFML CircleShape and initialise it so radius is 100
    sf::CircleShape shape(1);

    // Set the shape's fill colour attribute to Green
    shape.setFillColor(sf::Color::Green);

    Blob b = Blob({ 100, 100 });

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
        
        for (int x = 0; x < utilities::k_width; x++)
        {
	        for(int y = 0; y < utilities::k_height; y++)
	        {
                shape.setPosition(static_cast<float>(x), static_cast<float>(y));
                // work out the square distance between the points and the centre
                int d = std::hypot((b.m_position.x - x), (b.m_position.y - y));
	        	// Colour is inversely proportionate to the distance 
                int col = 1000 * b.m_radius / d;
                shape.setFillColor({static_cast<uint8_t>(col), static_cast<uint8_t>(col), static_cast<uint8_t>(col) });
                window.draw(shape);
	        }
        }

        b.Render(window);
        b.Update();
    	
        // Get the window to display its contents
        window.display();
    }


    return 0;
}
