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
    float distance = sqrt(dotP((position - other.position), (position - other.position)));
    acceleration += G_CONST * other.mass * (other.position - position) / distance / distance / distance;
}
void Particle::update(float dt) {
    velocity += dt * acceleration;
    position += dt * velocity;
    //acceleration = sf::Vector2f(.0f, .0f);
}

Particle::~Particle() {
}
