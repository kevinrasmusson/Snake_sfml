//
// Created by kevin on 2023-10-20.
//

#ifndef SNAKE_SNAKESEGMENT_H
#define SNAKE_SNAKESEGMENT_H
#include "Snake.h"
#include "Direction.h"
#include "Food.h"

class SnakeSegment {
public:
    SnakeSegment();
    void AddSnake();
    void draw(sf::RenderWindow& window) const;
    void setDirection(Direction dir);
    Direction OppositeDirection(Direction dir);
    void applyDirection(Snake &snake, Direction dir);
    size_t Size();
    bool snakeCollison();
    void start();
    bool foodCollision(Food& food);
private:
    std::vector<Snake> snakes;
    std::vector<sf::Vector2f> movementQueue;
    Direction prevDir;

};


#endif //SNAKE_SNAKESEGMENT_H
