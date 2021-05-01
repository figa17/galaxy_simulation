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

Particle::Particle(float r, float m) {
    mass = m;
    radius = r;
    position = sf::Vector2f(.0f, .0f);
    velocity = sf::Vector2f(.0f, .0f);
    acceleration = sf::Vector2f(.0f, .0f);
}

void Particle::setRadius(float r) {
    radius = r;
}

float Particle::getRadius() {
    return radius;
}
float Particle::getMass() {
    return mass;
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
void Particle::setVelocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}

void Particle::pulledBy(const Particle &other) {
    float mag = magnitude(other.position, position);

    // std::cout << mag << std::endl;
    sf::Vector2f distance = other.position - position;
    float m = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
    distance = distance / m;

    sf::Vector2f force = ((G_CONST * other.mass) / mag) * distance;
    acceleration = acceleration + force;
    // std::cout << acceleration.x << " -- " << acceleration.y << std::endl;
}
void Particle::update(float dt) {
    sf::Vector2f up = dt * acceleration;
    velocity = velocity + up;
    up = dt * velocity;
    position = position + up;
    acceleration = sf::Vector2f(.0f, .0f);
}

Particle::~Particle() {
}
