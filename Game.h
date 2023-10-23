/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "SnakeSegment.h"
#include "Snake.h"
class Game {
public:
    Game();
    bool wallCollision(Snake& snakeSegment, sf::RenderWindow& window);
    bool foodCollision(Snake& snakeSegment, Food& food);
private:
    std::vector<SnakeSegment> snakes;
};


#endif //SNAKE_GAME_H
