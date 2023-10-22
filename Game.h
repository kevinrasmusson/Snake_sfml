//
// Created by kevin on 2023-10-20.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Snake.h"
#include "SnakeSegment.h"

class Game {
public:
    Game();
    bool wallCollision(SnakeSegment& snakeSegment,sf::RenderWindow& window);
    bool foodCollision(SnakeSegment& snakeSegment,Food& food);
private:
    std::vector<Snake> snakes;
};


#endif //SNAKE_GAME_H
