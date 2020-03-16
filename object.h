#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
#include "animation.h"

struct Object
{
    Vector2i position;
    Vector2u visibleSize;
    IntRect collision;
    Texture texture;
    Animation animation;

    Object();
    void draw(RenderWindow& window);
};

#endif // OBJECT_H_INCLUDED
