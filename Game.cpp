/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Direction.h"
#include "SnakeSegment.h"
#include "Snake.h"
#include "Food.h"
Game::Game() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "SnakeSegment");
    window.setFramerateLimit(15);
    Snake snakeSegment;
    Food food(200,200);
    snakeSegment.start();
    bool isGameOver = false;
    bool isUp = false;
    bool isDown = false;
    bool isLeft = false;
    bool isRight = false;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                isLeft = true;
                isRight = false;
                isDown = false;
                isUp = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                isRight = true;
                isLeft = false;
                isDown = false;
                isUp = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                isUp = true;
                isRight = false;
                isDown = false;
                isLeft = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                isDown = true;
                isRight = false;
                isLeft = false;
                isUp = false;
            }

        }
        if (isUp){
            snakeSegment.setDirection(Up);
        }
        else if (isLeft){
            snakeSegment.setDirection(Left);
        }
        else if(isRight){
            snakeSegment.setDirection(Right);
        }
        else if(isDown){
            snakeSegment.setDirection(Down);
        }
        if (foodCollision(snakeSegment, food)){
            std::cout << "Food collision" << std::endl;
            food.setPos();
            snakeSegment.AddSnake();
        }
        if (wallCollision(snakeSegment,window)){
            std::cout << "Wall collision" << std::endl;
            isGameOver = true;
        }
        if (snakeSegment.snakeCollison()){
            std::cout << "SnakeSegment collision" << std::endl;
            isGameOver = true;
        }
        if (isGameOver) {
            snakeSegment.start();
            isUp = false;
            isDown = false;
            isLeft = false;
            isRight = false;
            isGameOver = false; // Reset the game state
        }
        window.clear();
        snakeSegment.draw(window);
        food.draw(window);
        window.display();
    }



}
/**
 * This function checks for collision between the snake's head and the "walls" of the window
 * @param snakeSegment
 * @param window
 * @return boolean value
 */
bool Game::wallCollision(Snake &snake, sf::RenderWindow& window) {
    sf::Vector2f snakeHeadPos = snake.getSnakes()[0].getPos();
    sf::Vector2u windowSize = window.getSize();

    // Check if the snake's head goes out of the window's bounds
    if (snakeHeadPos.x < 0 || snakeHeadPos.x >= windowSize.x ||
        snakeHeadPos.y < 0 || snakeHeadPos.y >= windowSize.y) {
        return true;
    }
    return false;
}
/**
 * This function checks if the snake head collides with the food
 * @param snakeSegment
 * @param food
 * @return boolean value
 */
bool Game::foodCollision(Snake &snake, Food &food) {
    if (snake.getSnakes()[0].getPos() == food.getPos()){
        return true;
    }
    return false;
}
