#include "Spaceship.h"  // Include header-ul clasei Spaceship
#include <math.h>  // Necesită pentru funcția std::sqrt()

// Constructorul Spaceship - inițializează nava cu dimensiunea specificată
Spaceship::Spaceship(sf::Vector2f size) {
    shape.setSize(size);  // Setează dimensiunea navei
    shape.setFillColor(sf::Color::White);  // Face nava albă
    shape.setOrigin(size.x / 2, size.y / 2);  // Setează centrul drept origine pentru rotație și mișcare
    shape.setPosition(400, 300);  // Poziționează nava inițial în centrul ecranului
    targetPos = shape.getPosition();  // Inițial, ținta este chiar poziția inițială a navei
}

// Funcția pentru setarea unei noi ținte spre care nava se va deplasa
void Spaceship::setTarget(sf::Vector2f target) {
    targetPos = target;  // Salvează coordonatele destinației
}

// Actualizează poziția navei, mutând-o treptat spre țintă
void Spaceship::update() {
    sf::Vector2f direction = targetPos - shape.getPosition();  // Vectorul direcție dintre poziția curentă și țintă
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);  // Calculăm distanța până la țintă

    if (length > 2.0f) {  // Dacă nava nu este suficient de aproape de țintă
        direction /= length;  // Normalizăm vectorul direcție pentru a menține viteza constantă
        shape.move(direction * 2.0f);  // Mutăm nava cu o viteză de 2 unități pe frame
    }
}

// Desenează nava în fereastra de joc
void Spaceship::draw(sf::RenderWindow& window) {
    window.draw(shape);  // Desenează obiectul `shape` (forma navei)
}

// Returnează poziția curentă a navei
sf::Vector2f Spaceship::getPosition() const {
    return shape.getPosition();
}
