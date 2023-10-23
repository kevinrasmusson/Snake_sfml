/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#include "SnakeSegment.h"
#include <SFML/Graphics.hpp>
#include "Direction.h"

/**
 * Constructor for snake segments
 * @param x :position on x axis
 * @param y :position on y axis
 */
SnakeSegment::SnakeSegment(float x, float y) {
    rectangle.setSize(sf::Vector2f(20, 20));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(x,y);

}
/**
 * Function for getting the snake segment's position
 * @return Vector2f
 */
const sf::Vector2f &SnakeSegment::getPos() const {
    return rectangle.getPosition();
}

