#ifndef SPACEMANAGER_H
#define SPACEMANAGER_H

#include "Sky.h"
#include "EventObject.h"
#include <vector>

class SpaceManager {
public:
    SpaceManager(sf::Vector2f areaSize);
    void update(sf::Vector2f playerPos);
    void draw(sf::RenderWindow& window);

private:
    Sky sky;
    std::vector<EventObject> eventObjects;
};

#endif // SPACEMANAGER_H
