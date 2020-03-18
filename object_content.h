#ifndef OBJECT_CONTENT_H_INCLUDED
#define OBJECT_CONTENT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "animation.h"

struct ObjectContent
{
    Vector2f spriteSize;
    Vector2f spriteOrigin;
    Vector2u collision;
    Vector2u collisionOrigin;
    Texture texture;
    Animation animation;
};

extern ObjectContent objlib[1];

#endif // OBJECT_CONTENT_H_INCLUDED
