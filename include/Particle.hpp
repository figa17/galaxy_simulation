#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "util.hpp"

const float G_CONST = 0.00066742f;

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
    Particle(float r, float m);
    ~Particle();
    float getRadius();
    float getMass();
    void setRadius(float r);
    void setPosition(float x, float y);
    void setVelocity(float x, float y);
    void pulledBy(const Particle &particle);
    void update(float dt);
    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    sf::Vector2f getAcceleration();
};


#endif