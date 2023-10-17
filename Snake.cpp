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

void Snake::move(Direction dir) {
   if (dir == Direction::Up && lastDir != Direction::Down){
        rectangle.move(0.f, -0.5);
        lastDir = Direction::Up;
    }
    /*else if (dir == Direction::Up && lastDir == Direction::Down){
        rectangle.move(0.f, 0.5);
    }*/
    else if (dir == Direction::Down && lastDir != Direction::Up){
        rectangle.move(0.f, 0.5);
        lastDir = Direction::Down;
    }
   /* else if (dir == Direction::Down && lastDir == Direction::Up){
        rectangle.move(0.f, -0.5);
    }*/
    else if (dir == Direction::Right && lastDir != Direction::Left){
        rectangle.move(0.5, 0.f);
        lastDir = Direction::Right;
    }
    /*else if (dir == Direction::Right && lastDir == Direction::Left){
        rectangle.move(-0.5, 0.f);

    }*/
    else if (dir == Direction::Left && lastDir != Direction::Right){
        rectangle.move(-0.5, 0.f);
        lastDir = Direction::Left;
    }
    /*else if (dir == Direction::Left && lastDir == Direction::Right){
        rectangle.move(0.5, 0.f);
    }*/
    else{
        dir = lastDir;
    }

}
void Snake::draw(sf::RenderWindow& window) const {
    window.draw(rectangle);
}