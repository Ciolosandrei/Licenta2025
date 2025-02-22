#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>  // Include biblioteca SFML necesară pentru grafica navei

// Clasa Spaceship gestionează nava jucătorului
class Spaceship {
public:
    // Constructor: inițializează nava cu o dimensiune implicită de 50x50 pixeli
    Spaceship(sf::Vector2f size = sf::Vector2f(50, 50));

    // Setează o destinație spre care nava se va deplasa
    void setTarget(sf::Vector2f target);

    // Actualizează poziția navei pentru a se deplasa treptat spre țintă
    void update();

    // Desenează nava pe fereastra jocului
    void draw(sf::RenderWindow& window);

    // Returnează poziția curentă a navei
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape shape;  // Forma navei, definită ca un pătrat
    sf::Vector2f targetPos;  // Coordonatele țintei unde trebuie să ajungă nava
};

#endif // SPACESHIP_H
