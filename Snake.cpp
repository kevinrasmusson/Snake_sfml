//
// Created by kevin on 2023-10-17.
//

#include "Snake.h"
#include <SFML/Graphics.hpp>
#include "Direction.h"

Snake::Snake(float x, float y) {
    rectangle.setSize(sf::Vector2f(20, 20));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(x,y);

}
const sf::Vector2f &Snake::getPos() const {
    return rectangle.getPosition();
}

