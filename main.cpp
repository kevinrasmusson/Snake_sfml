#include <iostream>
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Snake.h"
#include "Game.h"
int main() {
    Game game;
   /* // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
//    window.setFramerateLimit(60);
    Snake snake(window.getSize().x/2, window.getSize().y/2);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        snake.addDirection(Up);
                        break;
                    case sf::Keyboard::Down:
                        snake.addDirection(Down);
                        break;
                    case sf::Keyboard::Left:
                        snake.addDirection(Left);
                        break;
                    case sf::Keyboard::Right:
                        snake.addDirection(Right);
                        break;
                    default:
                        break;
                }
            }

        }
        snake.move();
        window.clear();
        snake.draw(window);
        window.display();
    }
*/
    return 0;
}
