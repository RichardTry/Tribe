#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "animation.h"

struct Object
{
    int x;
    int y;
    sf::Sprite sprite;
    Animation animation;

    void draw(sf::RenderWindow& window);
    void setTexture(sf::Texture& texture);
};

#endif // OBJECT_H_INCLUDED
