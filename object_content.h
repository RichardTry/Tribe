#ifndef OBJECT_CONTENT_H_INCLUDED
#define OBJECT_CONTENT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "animation.h"

struct ObjectContent
{
    sf::Vector2f spriteSize;
    sf::Vector2f spriteOrigin;
    sf::Vector2u collision;
    //Vector2u collisionOrigin;
    sf::Texture texture;
    Animation animation;
};

#endif // OBJECT_CONTENT_H_INCLUDED
