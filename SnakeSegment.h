//
// Created by kevin on 2023-10-20.
//

#ifndef SNAKE_SNAKESEGMENT_H
#define SNAKE_SNAKESEGMENT_H
#include "Snake.h"
#include "Direction.h"
class SnakeSegment {
public:
    SnakeSegment();
    void AddSnake();
    void draw(sf::RenderWindow& window) const;
    void setDirection(Direction dir);
    Direction OppositeDirection(Direction dir);
    void applyDirection(Snake &snake, Direction dir);
    size_t Size();
private:
    std::vector<Snake> snakes;
    std::vector<sf::Vector2f> movementQueue;

};


#endif //SNAKE_SNAKESEGMENT_H
