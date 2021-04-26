#include <SFML/Graphics.hpp>
#include <iostream>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define VELOCITY .00001

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100.f, 100.f);
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(shape);
        
        //move shape        
        for (size_t i = 0; i < 300; i++) {
            shape.move(VELOCITY * i, VELOCITY * i);
            window.draw(shape);
            window.display();
        }
    }

    return 0;
}