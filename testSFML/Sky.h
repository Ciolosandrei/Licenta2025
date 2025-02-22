#ifndef SKY_H
#define SKY_H

#include <SFML/Graphics.hpp>
#include <vector>

class Sky {
public:
    Sky(int numStars, sf::Vector2f areaSize);
    void update(sf::Vector2f playerPos);
    void draw(sf::RenderWindow& window);

private:
    struct Star {
        sf::CircleShape shape;
        float colorShift; // Schimbare treptată a culorii
    };

    struct Galaxy {
        sf::CircleShape core;
        std::vector<sf::CircleShape> rings;
        float rotationSpeed;
        float colorShift;
    };

    std::vector<Star> stars;
    std::vector<Galaxy> galaxies;
    sf::Vector2f areaSize;

    void generateStars();
    void generateGalaxies();
};

#endif // SKY_H

