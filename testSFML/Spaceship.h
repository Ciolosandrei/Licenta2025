#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>

class Spaceship {
public:
    Spaceship(sf::Vector2f size = sf::Vector2f(50, 50));
    void setTarget(sf::Vector2f target);
    void update();
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape shape;
    sf::Vector2f targetPos;
};

#endif // SPACESHIP_H
