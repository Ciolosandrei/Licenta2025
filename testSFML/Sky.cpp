#include "Sky.h"
#include <cstdlib>
#include <cmath>

Sky::Sky(int numStars, sf::Vector2f areaSize) : areaSize(areaSize) {
    stars.reserve(numStars);
    generateStars();
    generateGalaxies();
}

void Sky::generateStars() {
    for (int i = 0; i < stars.capacity(); i++) {
        Star star;
        star.shape.setRadius(1 + rand() % 3);
        star.shape.setFillColor(sf::Color::White);
        star.shape.setPosition(rand() % static_cast<int>(areaSize.x), rand() % static_cast<int>(areaSize.y));
        star.colorShift = static_cast<float>(rand() % 100) / 100.0f;
        stars.push_back(star);
    }
}

void Sky::generateGalaxies() {
    int numGalaxies = 5; // Se pot ajusta
    for (int i = 0; i < numGalaxies; i++) {
        Galaxy galaxy;
        galaxy.core.setRadius(10);
        galaxy.core.setFillColor(sf::Color(200, 100, 255));
        galaxy.core.setPosition(rand() % static_cast<int>(areaSize.x), rand() % static_cast<int>(areaSize.y));
        galaxy.rotationSpeed = 0.1f + static_cast<float>(rand() % 10) / 50.0f;
        galaxy.colorShift = static_cast<float>(rand() % 100) / 100.0f;

        // Adăugăm inele
        for (int j = 0; j < 3; j++) {
            sf::CircleShape ring(15 + j * 10);
            ring.setFillColor(sf::Color::Transparent);
            ring.setOutlineColor(sf::Color(150 + j * 30, 100, 255 - j * 50));
            ring.setOutlineThickness(2);
            ring.setPosition(galaxy.core.getPosition() - sf::Vector2f(ring.getRadius(), ring.getRadius()));
            galaxy.rings.push_back(ring);
        }

        galaxies.push_back(galaxy);
    }
}

void Sky::update(sf::Vector2f playerPos) {
    for (auto& star : stars) {
        star.colorShift += 0.01f;
        int colorValue = static_cast<int>(std::abs(std::sin(star.colorShift)) * 255);
        star.shape.setFillColor(sf::Color(colorValue, colorValue, 255));
    }

    for (auto& galaxy : galaxies) {
        galaxy.colorShift += 0.005f;
        int colorValue = static_cast<int>(std::abs(std::sin(galaxy.colorShift)) * 255);
        galaxy.core.setFillColor(sf::Color(colorValue, 100, 255));

        for (auto& ring : galaxy.rings) {
            ring.rotate(galaxy.rotationSpeed);
        }
    }
}

void Sky::draw(sf::RenderWindow& window) {
    for (const auto& star : stars) {
        window.draw(star.shape);
    }
    for (const auto& galaxy : galaxies) {
        window.draw(galaxy.core);
        for (const auto& ring : galaxy.rings) {
            window.draw(ring);
        }
    }
}
