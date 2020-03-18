#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;

struct Unit
{
    Vector2f position;
    unsigned int contentID;
    unsigned int direction;

    void draw(RenderWindow& window);
};

#endif // UNIT_H_INCLUDED
