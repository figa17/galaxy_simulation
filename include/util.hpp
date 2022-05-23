#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

float magnitude(const sf::Vector2f v1, const sf::Vector2f v2);
std::string readFile(const char *filePath); 

#endif