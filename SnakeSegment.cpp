//
// Created by kevin on 2023-10-20.
//

#include "SnakeSegment.h"
SnakeSegment::SnakeSegment() {}
void SnakeSegment::AddSnake() {
    if (snakes.empty()){
        snakes.emplace_back(400,300);
    }
    else{
        snakes.emplace_back(snakes.back().getPos().x + 20, snakes.back().getPos().y);
    }

}

void SnakeSegment::start() {
    if (!snakes.empty()){
        snakes.clear();
    }
    for (int i = 0; i < 10; ++i) {
        AddSnake();
    }
}
bool SnakeSegment::snakeCollison() {
    for (int i = 1; i < snakes.size(); ++i) {
        if (snakes[0].getPos() == snakes[i + 1].getPos()){
            return true;
        }
    }
    return false;
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
    if (prevDir != OppositeDirection(dir)){
        applyDirection(snakes[0], dir);
    }
    else{
        applyDirection(snakes[0], prevDir);
    }
    std::vector<sf::Vector2f> prevPositions;
    for (auto & snake : snakes) {
        prevPositions.push_back(snake.rectangle.getPosition());
    }

    // Restore the previous positions for the rest of the segments
    for (int i = 1; i < snakes.size(); i++) {
        snakes[i].rectangle.setPosition(prevPositions[i - 1]);
    }
}


void SnakeSegment::applyDirection(Snake &snake, Direction dir) {
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

bool SnakeSegment::foodCollision(Food& food) {
    if (snakes[0].getPos() == food.getPos()){
        return true;
    }
    return false;
}
size_t SnakeSegment::Size() {
    return snakes.size();
}