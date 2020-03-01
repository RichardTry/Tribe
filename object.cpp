#include "object.h"

void Object::draw(sf::RenderWindow& window)
{
    sprite.setPosition(x * 32, y * 32);
    window.draw(sprite);
}

void Object::setTexture(sf::Texture& texture)
{
    sprite.setTexture(texture);
}
