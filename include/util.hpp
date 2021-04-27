#ifndef UTIL_H
#define UTIL_H
#pragma once

#include <cmath>
#include <iostream>

float gravity() {
    return .0f;
}

float dotProdcut(const sf::Vector2f v1,const sf::Vector2f v2){
    return (v1.x * v2.x)+(v1.y*v2.y);
}

#endif