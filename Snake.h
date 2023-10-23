//
// Created by kevin on 2023-10-20.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include "SnakeSegment.h"
#include "Direction.h"
#include "Food.h"

class Snake {
public:
    Snake();
    void AddSnake();
    void draw(sf::RenderWindow& window) const;
    void setDirection(Direction dir);
    Direction OppositeDirection(Direction dir);
    void applyDirection(SnakeSegment &snake, Direction dir);
    size_t Size();
    bool snakeCollison();

    const std::vector<SnakeSegment> &getSnakes() const;

    void start();

private:
    std::vector<SnakeSegment> snakes;
    std::vector<sf::Vector2f> movementQueue;
    Direction prevDir;

};


#endif //SNAKE_SNAKE_H
