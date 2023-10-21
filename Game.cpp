//
// Created by kevin on 2023-10-20.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Direction.h"
#include "Snake.h"
#include "SnakeSegment.h"
#include "Food.h"

Game::Game() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    window.setFramerateLimit(15);
    SnakeSegment snakeSegment;
    Food food(10,10);
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
        if (snakeSegment.snakeCollison()){
            std::cout << "Snake collision" << std::endl;
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
        if (snakeSegment.foodCollision(food)){
            snakeSegment.AddSnake();
        }
        window.clear();
        snakeSegment.draw(window);
        food.draw(window);
        window.display();
    }



}
