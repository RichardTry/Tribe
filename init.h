#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "object_content.h"
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 1120;
const int SCREEN_HEIGHT = 630;

ObjectContent objlib[1];

void Init()
{
    srand(time(nullptr));
    objlib[0].visibleSize = Vector2u(2, 2);
    objlib[0].collision = Vector2u(2, 2);

    camera.setSize(16, 9);
    camera.setCenter(0,0);
}

#endif // INIT_H_INCLUDED
