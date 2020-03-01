#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

const int MAP_MULT = 3;
const int MAP_SIZE = pow(2, MAP_MULT);

struct Map
{
    uint8_t height_map[MAP_SIZE][MAP_SIZE];
    void generate();
    void draw(RenderWindow& window);
};

#endif // MAP_H_INCLUDED
