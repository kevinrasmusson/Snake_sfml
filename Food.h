/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "SnakeSegment.h"
#include "Snake.h"

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
