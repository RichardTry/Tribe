#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include "tile.h"
#include "object.h"

const unsigned int CHUNK_SIZE = 32;

//const Texture tileset;

struct Chunk
{
    Vector2u position;
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
    std::vector<Object> objects;
    void draw(RenderWindow& window, Texture* tileset);
};

#endif // CHUNK_H_INCLUDED
