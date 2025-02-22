#include "Spaceship.h"
#include <cmath>

Spaceship::Spaceship(sf::Vector2f size) {
    shape.setSize(size);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(size.x / 2, size.y / 2);
    shape.setPosition(400, 300);
    targetPos = shape.getPosition();
}

void Spaceship::setTarget(sf::Vector2f target) {
    targetPos = target;
}

void Spaceship::update() {
    sf::Vector2f direction = targetPos - shape.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 6.0f) {
        direction /= length;
        shape.move(direction * 6.0f);
    }
}

void Spaceship::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Spaceship::getPosition() const {
    return shape.getPosition();
}

