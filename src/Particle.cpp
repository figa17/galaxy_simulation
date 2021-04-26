#include "../include/Particle.hpp"

Particle::Particle(float r, float m, sf::Vector2f pos) {
    mass = m;
    radius = r;
    position = pos;
}

Particle::~Particle() {
}