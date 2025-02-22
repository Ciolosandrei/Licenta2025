#ifndef SPACEMANAGER_H
#define SPACEMANAGER_H

#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "Sky.h"
#include "EventObject.h"

class SpaceManager {
public:
    SpaceManager();
    void update();
    void draw(sf::RenderWindow& window);
    void setPlayerTarget(sf::Vector2f target); // Setează ținta pentru navă

private:
    Spaceship player;
    Sky sky;
    EventObject asteroid;
};

#endif // SPACEMANAGER_H
