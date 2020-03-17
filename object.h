#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;

struct Object
{
    Vector2i position;
    unsigned int contentID;

    Object();
    void draw(RenderWindow& window);
};

#endif // OBJECT_H_INCLUDED
