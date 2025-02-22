#include "Sky.h"  // Include header-ul clasei Sky pentru a implementa metodele definite în el
#include <cstdlib> // Include biblioteca pentru funcția rand(), utilizată la generarea stelelor

// Constructorul clasei Sky
Sky::Sky(int numStars, sf::Vector2f areaSize) : areaSize(areaSize) {
    stars.reserve(numStars); // Prealocă spațiu în vector pentru a evita realocări multiple
    generateStars(); // Apelează funcția de generare a stelelor
}

// Funcție privată care generează stelele în poziții aleatorii
void Sky::generateStars() {
    for (int i = 0; i < stars.capacity(); i++) { // Iterează de la 0 până la numărul de stele alocat
        sf::CircleShape star(2); // Creează o stea cu raza de 2 pixeli
        star.setFillColor(sf::Color::White); // Setează culoarea stelei la alb
        // Plasează steaua într-o poziție aleatorie în cadrul zonei specificate
        star.setPosition(rand() % static_cast<int>(areaSize.x), rand() % static_cast<int>(areaSize.y));
        stars.push_back(star); // Adaugă steaua în vector
    }
}

// Funcție care actualizează poziția stelelor în funcție de poziția jucătorului
void Sky::update(sf::Vector2f playerPos) {
    for (auto& star : stars) { // Iterează prin fiecare stea din vector
        sf::Vector2f pos = star.getPosition(); // Obține poziția stelei
        // Verifică dacă steaua a ieșit din zona vizibilă definită în jurul jucătorului
        if (pos.x < playerPos.x - areaSize.x / 2 || pos.x > playerPos.x + areaSize.x / 2 ||
            pos.y < playerPos.y - areaSize.y / 2 || pos.y > playerPos.y + areaSize.y / 2) {
            // Relocare aleatorie a stelei în noua zonă generată în jurul jucătorului
            star.setPosition(playerPos.x + rand() % static_cast<int>(areaSize.x) - areaSize.x / 2,
                             playerPos.y + rand() % static_cast<int>(areaSize.y) - areaSize.y / 2);
        }
    }
}

// Funcție care desenează stelele pe ecran
void Sky::draw(sf::RenderWindow& window) {
    for (const auto& star : stars) { // Iterează prin fiecare stea
        window.draw(star); // Desenează steaua pe fereastra de joc
    }
}
