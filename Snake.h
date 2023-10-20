//
// Created by kevin on 2023-10-17.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <SFML/Graphics.hpp>
#include "Direction.h"

class Snake {
public:
    Snake(float x, float y);
    void move(Direction dir);
    void draw(sf::RenderWindow& window) const;
    sf::RectangleShape rectangle;
    Direction lastDir = Up;
    void AddSnake();
private:
    std::vector<Snake> snakeSection;

};


#endif //SNAKE_SNAKE_H
