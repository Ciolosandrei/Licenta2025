#include "EventObject.h"

EventObject::EventObject(sf::Vector2f position, sf::Vector2f size) {
   // shape.setSize(size); //definea dimensiunea implicită a acestor obiecte.
  //   shape.setFillColor(sf::Color::Red); //colora obiectele în roșu atunci când nu aveau textură.
    shape.setOrigin(size.x / 2, size.y / 2);
    shape.setPosition(position);
}

void EventObject::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect EventObject::getBounds() const {
    return shape.getGlobalBounds();
}
