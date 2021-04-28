#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <random>

#include "include/Particle.hpp"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define VELOCITY .00001
const int n = 20000;
constexpr float dt = 1.0 / 40.0f;

void initGalaxy(Particle centre, Particle extras[]) {
    /* Initializing first galaxy */
    centre = Particle(2000.0f, 2.5f);
    centre.setPosition(150.0f, 20.0f);
    centre.setVelocity(-5.0f, 0.0f);

    //change distribution of particles (optional)
    float maxRadius = 30.0f;  //max radius of the galaxy
    float theta = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * M_PI * 2;
    ;  //angle the particle makes with the centre
    float r = 1.0f + ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * maxRadius);
    r = r * r / maxRadius;
    r += 0.2f * centre.getRadius();

    float offset = 0.6f;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(-offset, offset);

    for (int i = 0; i < n; i++) {
        extras[i].setPosition(r * cos(theta), r * sin(theta));                     //polar to cartezian coordinates
        extras[i].getPosition() = extras[i].getPosition() + centre.getPosition();  //move the particle relative to the centre

        float v = sqrt(G_CONST * centre.getMass() / r);  //calculate velocity based on radius

        sf::Vector2f velocityUpdate(0, 0);
        velocityUpdate += sf::Vector2f(v * sin(theta), -v * cos(theta));  //polar to cartezian coordinates, rotated by 90 degrees
        velocityUpdate += sf::Vector2f(dist(mt), dist(mt));               //random offset to velocity
        velocityUpdate += centre.getVelocity();

        extras[i].setVelocity(velocityUpdate.x, velocityUpdate.y);
        extras[i].setRadius(0.2f);
    }
}

int main() {
    /* Initializing first galaxy */
    Particle centre1(2000.0f, 2.5f);
    centre1.setPosition(150.0f, 20.0f);
    centre1.setVelocity(-5.0f, 0.0f);
    Particle bodies1[n];

    Particle centre2(2000.0f, 2.5f);
    centre2.setPosition(-centre1.getPosition().x, -centre1.getPosition().y);
    centre2.setVelocity(-centre1.getVelocity().x, -centre1.getVelocity().y);
    Particle bodies2[n];

    initGalaxy(centre1, bodies1);
    initGalaxy(centre2, bodies2);

    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        centre1.pulledBy(centre2);
        centre2.pulledBy(centre1);

        //particles are attracted to centres
        for (int i = 0; i < n; i++) {
            bodies1[i].pulledBy(centre1);
            bodies2[i].pulledBy(centre1);
            bodies1[i].pulledBy(centre2);
            bodies2[i].pulledBy(centre2);
        }

        //update bodies
        centre1.update(dt);
        centre2.update(dt);
        sf::Vector2f pos;
        for (int i = 0; i < n; i++) {
            bodies1[i].update(dt);
            bodies2[i].update(dt);

            sf::CircleShape shapeb1(1.f);
            shapeb1.setFillColor(sf::Color::Green);
            pos = bodies1[i].getPosition();
            shapeb1.setPosition(pos.x, pos.y);
            window.draw(shapeb1);

            sf::CircleShape shapeb2(1.f);
            shapeb2.setFillColor(sf::Color::Green);
            pos = bodies2[i].getPosition();
            shapeb1.setPosition(pos.x, pos.y);
            window.draw(shapeb2);
        }
        window.display();
    }

    return 0;
}