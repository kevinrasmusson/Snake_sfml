//
// Created by kevin on 2023-10-17.
//

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

void Food::setPos(const sf::Vector2f &pos) {
    circle.setPosition(pos);
}