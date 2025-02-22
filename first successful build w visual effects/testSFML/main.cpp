#include <SFML/Graphics.hpp>
#include "SpaceManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Exploration", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    SpaceManager spaceManager;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f target = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                spaceManager.setPlayerTarget(target); // ✅ Trimitem poziția țintă
            }
        }

        spaceManager.update();

        window.clear();
        spaceManager.draw(window);
        window.display();
    }

    return 0;
}

