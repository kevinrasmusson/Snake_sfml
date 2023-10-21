//
// Created by kevin on 2023-10-17.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Snake.h"
#include "SnakeSegment.h"

class Food {
public:
    Food(float x, float y);
    sf::CircleShape circle;
    const sf::Vector2f &getPos() const;
    void setPos();
    void draw(sf::RenderWindow& window) const;

private:
};


#endif //SNAKE_FOOD_H
