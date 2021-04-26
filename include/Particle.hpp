#ifndef PARTICLE_H
#define PARTICLE_H
#pragma once

#include <iostream>
#include <SFML/Graphics/Vertex.hpp>

class Particle {
   private:
    float r;
    float m;

   public:
    Particle();
    ~Particle();
};
#endif