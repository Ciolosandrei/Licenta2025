#include "SpaceManager.h"

SpaceManager::SpaceManager(sf::Vector2f areaSize) : sky(200, areaSize) { // Fundal mai mic
    eventObjects.emplace_back(sf::Vector2f(600, 400)); // Un singur asteroid
}

void SpaceManager::update(sf::Vector2f playerPos) {
    sky.update(playerPos);
}

void SpaceManager::draw(sf::RenderWindow& window) {
    sky.draw(window);
    for (auto& obj : eventObjects) {
        obj.draw(window);
    }
}
