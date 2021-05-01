#include "../include/util.hpp"

float magnitude(const sf::Vector2f v1, const sf::Vector2f v2) {
    float distx = v2.x - v1.x;
    float disty = v2.y - v1.y;
    return sqrt(pow(distx, 2) + pow(disty, 2));
}
