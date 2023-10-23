/**
 *@author Kevin Rasmusson
 *@version 1.1
 */
#include <cmath>
#include "Food.h"
/**
 * Constructor for food objects
 * @param x :position on x axis
 * @param y :position on y axis
 */
Food::Food(float x, float y) {
    circle.setRadius(10);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(x,y);
}
/**
 * Function for getting the position of the food object
 * @return Vector2f
 */
const sf::Vector2f &Food::getPos() const {
    return circle.getPosition();
}
/**
 * Function for drawing the food
 * @param window
 */
void Food::draw(sf::RenderWindow &window) const {
    window.draw(circle);
}
/**
 * Function for setting the position of the food
 * Generates a random multiple of 20 for x and y
 */
void Food::setPos() {
    int randX = (std::rand() % 40) * 20;
    int randY = (std::rand() % 30) * 20;
    circle.setPosition(static_cast<float>(randX), static_cast<float>(randY));;
}