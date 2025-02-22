#ifndef SKY_H  // Previne includerea multiplă a acestui header în același fișier sursă
#define SKY_H

#include <SFML/Graphics.hpp>  // Include biblioteca SFML necesară pentru grafică
#include <vector>  // Include biblioteca STL pentru utilizarea vectorilor

// Clasa Sky gestionează stelele și fundalul spațial
class Sky {
public:
    // Constructorul clasei Sky - primește numărul de stele și dimensiunea zonei în care sunt generate
    Sky(int numStars, sf::Vector2f areaSize);

    // Funcție care actualizează poziția stelelor pe baza poziției jucătorului
    void update(sf::Vector2f playerPos);

    // Funcție care desenează stelele pe fereastra de joc
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::CircleShape> stars; // Vector care stochează toate stelele desenate pe ecran
    sf::Vector2f areaSize; // Dimensiunea zonei în care sunt generate stelele

    // Funcție privată care generează stelele inițial
    void generateStars();
};

#endif // SKY_H  // Încheierea directivei de preprocesare pentru prevenirea includerii multiple
