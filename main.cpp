#include <iostream>
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Snake.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    Snake snake(window.getSize().x/2, window.getSize().y/2);
    Direction currentDir;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        currentDir = Direction::Up;
                        break;
                    case sf::Keyboard::Down:
                        currentDir = Direction::Down;
                        break;
                    case sf::Keyboard::Left:
                        currentDir = Direction::Left;
                        break;
                    case sf::Keyboard::Right:
                        currentDir = Direction::Right;
                        break;
                    default:
                        break;

                }

            }
        }
        snake.move(currentDir);
        window.clear();
        snake.draw(window);
        window.display();
    }

    return 0;
}
