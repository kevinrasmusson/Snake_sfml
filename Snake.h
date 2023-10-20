//
// Created by kevin on 2023-10-17.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include <queue>

class Snake {
public:
    Snake(float x, float y);
   /* void move();
    void setDirection(sf::Vector2f newPos);
    void addDirection(Direction dir);
    void draw(sf::RenderWindow& window) const;*/
    sf::RectangleShape rectangle;
    const sf::Vector2f &getPos() const;

    void setPos(const sf::Vector2f &pos);

private:
    sf::Vector2f pos;
    std::vector<Direction> movementQueue;
    void applyDirection(Direction dir);

};


#endif //SNAKE_SNAKE_H
