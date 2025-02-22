#include "SpaceManager.h"

SpaceManager::SpaceManager()
    : sky(150, sf::Vector2f(1920, 1080)),  // 150 stele pe o zonă mare
      asteroid(sf::Vector2f(600, 400), sf::Vector2f(50, 50)) { // Asteroid mai mic
}

void SpaceManager::setPlayerTarget(sf::Vector2f target) {
    player.setTarget(target);
}

void SpaceManager::update() {
    player.update();
    sky.update(player.getPosition());
}

void SpaceManager::draw(sf::RenderWindow& window) {
    sky.draw(window);
    player.draw(window);
    asteroid.draw(window);
}
