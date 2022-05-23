#include "../include/util.hpp"

float magnitude(const sf::Vector2f v1, const sf::Vector2f v2) {
    float distx = v2.x - v1.x;
    float disty = v2.y - v1.y;
    return sqrt(pow(distx, 2) + pow(disty, 2));
}

std::string readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}