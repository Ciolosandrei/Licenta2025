#ifndef EVENTOBJECT_H
#define EVENTOBJECT_H

#include <SFML/Graphics.hpp>  // Include biblioteca SFML necesară pentru desenarea obiectelor grafice

// Clasa EventObject reprezintă un obiect cu care jucătorul poate interacționa
class EventObject {
public:
    // Constructor: inițializează obiectul la o anumită poziție și dimensiune
    EventObject(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(40, 40)); // Dimensiune implicită de 40x40 pixeli

    // Funcție pentru desenarea obiectului în fereastra de joc
    void draw(sf::RenderWindow& window);

    // Returnează un dreptunghi ce reprezintă limitele obiectului, util pentru detecția coliziunii
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;  // Reprezentarea grafică a obiectului (un pătrat sau un dreptunghi)
};

#endif // EVENTOBJECT_H
