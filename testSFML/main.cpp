#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "SpaceManager.h"

int main() {
    // Obține dimensiunea ecranului și creează fereastra la rezoluția maximă
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Space Explorer", sf::Style::Fullscreen);

    // Inițializează obiectele din joc
    Spaceship spaceship(sf::Vector2f(50, 50)); // Navă mai mică
    SpaceManager spaceManager(sf::Vector2f(desktop.width * 2, desktop.height * 2)); // Fundal adaptat

    sf::View camera(sf::FloatRect(0, 0, desktop.width, desktop.height));
    camera.zoom(0.7f); // Zoom pentru a vedea mai mult

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                spaceship.setTarget(mousePos);
            }
        }

        spaceship.update();
        spaceManager.update(spaceship.getPosition());
        camera.setCenter(spaceship.getPosition());
        window.setView(camera);

        window.clear();
        spaceManager.draw(window);
        spaceship.draw(window);
        window.display();
    }

    return 0;
}
