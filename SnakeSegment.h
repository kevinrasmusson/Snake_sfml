/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#ifndef SNAKE_SNAKESEGMENT_H
#define SNAKE_SNAKESEGMENT_H
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include <vector>

class SnakeSegment {
public:
    SnakeSegment(float x, float y);
    sf::RectangleShape rectangle;
    const sf::Vector2f &getPos() const;



private:
    std::vector<Direction> movementQueue;

};


#endif //SNAKE_SNAKESEGMENT_H
