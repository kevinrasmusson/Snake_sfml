/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#include <iostream>
#include "Snake.h"
/**
 * Default constructor for Snake
 */
Snake::Snake() {}
void Snake::AddSnake() {
    if (snakes.empty()){
        snakes.emplace_back(400,300);
    }
    else{
        snakes.emplace_back(snakes.back().getPos().x + 20, snakes.back().getPos().y);
    }

}
/**
 * Function for setting the starting position of the snake
 */
void Snake::start() {
    if (!snakes.empty()){
        snakes.clear();
        prevDir = None;
    }
    for (int i = 0; i < 10; ++i) {
        AddSnake();
    }
}
/**
 * Function for checking if the snake head collides with the rest of the snake
 * @return boolean value
 */
bool Snake::snakeCollison() {
    for (int i = 1; i < snakes.size(); ++i) {
        if (snakes[0].getPos() == snakes[i + 1].getPos()){
            return true;
        }
    }
    return false;
}
/**
 * Function for drawing the snake
 * @param window
 */
void Snake::draw(sf::RenderWindow &window) const {
    for (const auto & snake : snakes) {
        window.draw(snake.rectangle);
    }
}
/**
 * Function for getting the opposite direction of input value
 * @param dir
 * @return boolean value
 */
Direction Snake::OppositeDirection(Direction dir) {
    if (dir == Up){
        return Down;
    }
    else if(dir == Down){
        return Up;
    }
    else if(dir == Left){
        return Right;
    }
    return Left;
}
/**
 * Function for setting the direction of the snake.
 * Vector prevPosition is created in function, this is to minimize resource management.
 *
 * @param dir
 */
void Snake::setDirection(Direction dir) {
    if (prevDir != OppositeDirection(dir)){
        applyDirection(snakes[0], dir);
    }
    else{
        applyDirection(snakes[0], prevDir);
    }
    std::vector<sf::Vector2f> prevPositions;
    for (auto & snake : snakes) {
        prevPositions.push_back(snake.getPos());
    }

    // Restore the previous positions for the rest of the segments
    for (int i = 1; i < snakes.size(); i++) {
        snakes[i].rectangle.setPosition(prevPositions[i - 1]);
    }

}

/**
 * Function for applying the direction given to the first snake segment
 * @param snake
 * @param dir
 */
void Snake::applyDirection(SnakeSegment &snake, Direction dir) {
    if (dir == Up) {
        snake.rectangle.move(0.f, -20);
        prevDir = Up;
    } else if (dir == Down) {
        snake.rectangle.move(0.f, 20);
        prevDir = Down;
    } else if (dir == Right) {
        snake.rectangle.move(20, 0.f);
        prevDir = Right;
    } else if (dir == Left) {
        snake.rectangle.move(-20, 0.f);
        prevDir = Left;
    }

}
/**
 * Function for returning the snake vector
 * @return vector
 */
const std::vector<SnakeSegment> &Snake::getSnakes() const {
    return snakes;
}
