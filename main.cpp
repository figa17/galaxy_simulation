#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <random>

#include "include/Particle.hpp"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define VELOCITY .001
const int n = 20000;
constexpr float dt = 1.0 / 400.0f;

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

    sf::Vector2f updatePos;
    for (int i = 0; i < n; i++) {
        extras[i].setPosition(r * cos(theta), r * sin(theta));  //polar to cartezian coordinates
        updatePos = extras[i].getPosition() + centre.getPosition();
        extras[i].setPosition(updatePos.x, -updatePos.y);  //move the particle relative to the centre
        std::cout << updatePos.x << " --- " << updatePos.y << std::endl;
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
    centre1.setPosition(10.0f, 10.0f);
    centre1.setVelocity(-5.0f, 0.0f);
    Particle bodies1[n];

    Particle centre2(2000.0f, 2.5f);
    centre2.setPosition(100 + centre1.getPosition().x, 100 + centre1.getPosition().y);
    centre2.setVelocity(-centre1.getVelocity().x, -centre1.getVelocity().y);
    Particle bodies2[n];

    initGalaxy(centre1, bodies1);
    initGalaxy(centre2, bodies2);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    sf::VertexArray pointsBodiesC1(sf::Points, n + 1);
    sf::VertexArray pointsBodiesC2(sf::Points, n + 1);

    // points[0].setFillColor(sf::Color::Blue);
    pointsBodiesC1[0].position = centre1.getPosition();
    pointsBodiesC2[0].position = centre2.getPosition();
    // sf::CircleShape shapeb2(20.f);
    // shapeb2.setFillColor(sf::Color::Red);
    // shapeb2.setPosition(centre2.getPosition().x, centre2.getPosition().y);

    window.clear(sf::Color::Black);

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        centre1.pulledBy(centre2);
        centre2.pulledBy(centre1);
        window.clear(sf::Color::Black);
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

        pointsBodiesC1[0].position = centre1.getPosition();
        pointsBodiesC1[0].color = sf::Color::Red;
        pointsBodiesC2[0].position = centre2.getPosition();
        pointsBodiesC2[0].color = sf::Color::Green;

        for (int i = 0; i < n; i++) {
            bodies1[i].update(dt);
            bodies2[i].update(dt);

            pointsBodiesC1[i + 1].position = bodies1[i].getPosition();
            pointsBodiesC1[i + 1].color = sf::Color::Red;
            pointsBodiesC2[i + 1].position = bodies2[i].getPosition();
            pointsBodiesC2[i + 1].color = sf::Color::Green;
        }
        window.draw(pointsBodiesC1);
        window.draw(pointsBodiesC2);
        window.display();
    }

    return 0;
}