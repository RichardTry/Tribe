#ifndef UNIT_CONTENT_H_INCLUDED
#define UNIT_CONTENT_H_INCLUDED

#include "animation.h"

struct UnitContent
{
    sf::Vector2f spriteSize;
    sf::Vector2f spriteOrigin;
    sf::Vector2f collision;
    sf::Vector2f collisionOrigin;
    sf::Texture texture;
};

#endif // UNIT_CONTENT_H_INCLUDED
