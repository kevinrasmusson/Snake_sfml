//
// Created by kevin on 2023-10-20.
//

#include "SnakeSegment.h"
SnakeSegment::SnakeSegment() {
    movementQueue.emplace_back(400,300);
}
void SnakeSegment::AddSnake() {
    if (snakes.empty()){
        snakes.emplace_back(400,300);
    }
    else{
        snakes.emplace_back(snakes.back().getPos().x + 20, snakes.back().getPos().y);
    }

}

void SnakeSegment::draw(sf::RenderWindow &window) const {
    for (const auto & snake : snakes) {
        window.draw(snake.rectangle);
    }
}

Direction SnakeSegment::OppositeDirection(Direction dir) {
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
void SnakeSegment::setDirection(Direction dir) {
   /* if (movementQueue.empty()) {
        // If the movementQueue is empty, start moving in the new direction
        movementQueue.push_back(dir);
    } else {
        // If the movementQueue is not empty, check if the new direction is valid (not opposite to the current direction)
        Direction currentDir = movementQueue.back();
        if (dir != OppositeDirection(currentDir)) {
            movementQueue.push_back(dir);
        }
    }*/

    if (dir == Up) {
        snakes[0].rectangle.move(0.f, -20);
    } else if (dir == Down) {
        snakes[0].rectangle.move(0.f, 20);
    } else if (dir == Right) {
        snakes[0].rectangle.move(20, 0.f);
    } else if (dir == Left) {
        snakes[0].rectangle.move(-20, 0.f);
    }
    std::vector<sf::Vector2f> prevPositions;
    for (int i = 0; i < snakes.size(); i++) {
        prevPositions.push_back(snakes[i].rectangle.getPosition());
    }

    // Update the position of the head (snakes[0])
    applyDirection(snakes[0], dir);

    // Restore the previous positions for the rest of the segments
    for (int i = 1; i < snakes.size(); i++) {
        snakes[i].rectangle.setPosition(prevPositions[i - 1]);
    }
    /*for (int i = 0; i < snakes.size(); ++i) {
        if (movementQueue[i] == Up){
            snakes[i].rectangle.move(0.f, -0.5);
        }
        else if(movementQueue[i] == Down){
            snakes[i].rectangle.move(0.f, 0.5);
        }
        else if(movementQueue[i] == Right){
            snakes[i].rectangle.move(0.5, 0.f);
        }
        else if(movementQueue[i] == Left){
            snakes[i].rectangle.move(-0.5, 0.f);
        }

    }

    movementQueue.pop_back();*/
}


void SnakeSegment::applyDirection(Snake &snake, Direction dir) {
    if (dir == Up) {
        snake.rectangle.move(0.f, -0.5);
    } else if (dir == Down) {
        snake.rectangle.move(0.f, 0.5);
    } else if (dir == Right) {
        snake.rectangle.move(0.5, 0.f);
    } else if (dir == Left) {
        snake.rectangle.move(-0.5, 0.f);
    }

}

size_t SnakeSegment::Size() {
    return snakes.size();
}