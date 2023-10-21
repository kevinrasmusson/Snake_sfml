//
// Created by kevin on 2023-10-17.
//

#include <cmath>
#include "Food.h"
Food::Food(float x, float y) {
    circle.setRadius(10);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(x,y);
}

const sf::Vector2f &Food::getPos() const {
    return circle.getPosition();
}

void Food::draw(sf::RenderWindow &window) const {
    window.draw(circle);
}

void Food::setPos() {
    int randX = (std::rand() % 40) * 20;  // Generate a random multiple of 20 for X
    int randY = (std::rand() % 30) * 20;  // Generate a random multiple of 20 for Y
    circle.setPosition(static_cast<float>(randX), static_cast<float>(randY));;
}