#include "../include/Particle.hpp"

Particle::Particle() {
    mass = 1.0f;
    radius = 0.2f;
    position = sf::Vector2f(.0f, .0f);
    velocity = sf::Vector2f(.0f, .0f);
    acceleration = sf::Vector2f(.0f, .0f);
}

Particle::Particle(float m) {
    mass = m;
    radius = 0.2f * cbrt(m);
    position = sf::Vector2f(.0f, .0f);
    velocity = sf::Vector2f(.0f, .0f);
    acceleration = sf::Vector2f(.0f, .0f);
}

Particle::Particle(float r, float m, sf::Vector2f pos) {
    mass = m;
    radius = r;
    position = pos;
    velocity = sf::Vector2f(.0f, .0f);
    acceleration = sf::Vector2f(.0f, .0f);
}


sf::Vector2f Particle::getPosition() {
    return position;
}

sf::Vector2f Particle::getVelocity() {
    return velocity;
}
sf::Vector2f Particle::getAcceleration() {
    return acceleration;
}

void Particle::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Particle::pulledBy(const Particle &other) {
    // TODO completar la función de atracción utilizando vectores.
    float rest_x = pow((other.position.x - position.x), 2);
    float rest_y = pow((other.position.y - position.y), 2);
    float distance = sqrt(dotProdcut((position - other.position), (position - other.position)));
    
    float grav = G_CONST * other.mass;

    acceleration += (other.position - position) / distance / distance / distance;
}
void Particle::update(float dt) {}

Particle::~Particle() {
}