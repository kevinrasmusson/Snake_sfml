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

/*void Snake::addDirection(Direction dir) {
    movementQueue.push_back(dir);
}

void Snake::applyDirection(Direction dir) {
   // if (!movementQueue.empty()){
    if (dir == Up) {
        rectangle.move(0.f, -0.5);
    } else if (dir == Down) {
        rectangle.move(0.f, 0.5);
    } else if (dir == Right) {
        rectangle.move(0.5, 0.f);
    } else if (dir == Left) {
        rectangle.move(-0.5, 0.f);
    }
   // movementQueue.pop_back(); // Pop the direction after moving



}
void Snake::move() {
    if (!movementQueue.empty()){
        Direction nextDir = movementQueue.front();
        applyDirection(nextDir);
        movementQueue.pop_back();
    }
}

void Snake::setDirection(sf::Vector2f newPos) {
    pos = newPos;
}
void Snake::draw(sf::RenderWindow& window) const {
    window.draw(rectangle);
}*/

const sf::Vector2f &Snake::getPos() const {
    return rectangle.getPosition();
}

void Snake::setPos(const sf::Vector2f &pos) {
    rectangle.setPosition(pos);
}
