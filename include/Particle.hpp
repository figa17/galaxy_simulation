#ifndef PARTICLE_H
#define PARTICLE_H
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "util.hpp"

#define G 0.000000000066742;

class Particle {
   protected:
    float radius;
    float mass;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

   public:
    Particle();
    Particle(float m);
    Particle(float r, float m, sf::Vector2f pos);
    ~Particle();
    void setPosition(float x, float y);
    void pulledBy(const Particle &particle);
    void update(float dt);
    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    sf::Vector2f getAcceleration();

};
#endif