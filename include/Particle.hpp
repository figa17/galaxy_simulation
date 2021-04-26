#ifndef PARTICLE_H
#define PARTICLE_H
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Particle {
   private:
    float radius;
    float mass;
    sf::Vector2f position;

   public:
    Particle(float r, float m, sf::Vector2f pos);
    ~Particle();
};
#endif