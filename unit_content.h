#ifndef UNIT_CONTENT_H_INCLUDED
#define UNIT_CONTENT_H_INCLUDED

#include "animation.h"

struct UnitContent
{
    Vector2f spriteSize;
    Vector2f spriteOrigin;
    Vector2f collision;
    Vector2f collisionOrigin;
    Texture texture;
};

extern UnitContent unitlib[1];

#endif // UNIT_CONTENT_H_INCLUDED
