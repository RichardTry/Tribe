#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "object_content.h"
#include "unit_content.h"
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 1120;
const int SCREEN_HEIGHT = 630;

//Clock clock;

ObjectContent objlib[1];
UnitContent unitlib[1];

void Init()
{
    srand(time(nullptr));

    objlib[0].spriteSize = Vector2f(2, 3);
    objlib[0].collision = Vector2u(1, 1);
    objlib[0].spriteOrigin = Vector2f(0.5, 2);

    unitlib[0].spriteSize = Vector2f(1, 1);
    unitlib[0].spriteOrigin = Vector2f(0, 0);
    unitlib[0].collision = Vector2f(1, 1);
    unitlib[0].collisionOrigin = Vector2f(0, 0);

    camera.setSize(16, 9);
    camera.setCenter(0,0);
}

#endif // INIT_H_INCLUDED
