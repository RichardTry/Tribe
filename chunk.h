#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
#include <algorithm>
#include <vector>
#include "tile.h"
#include "object.h"

const unsigned int CHUNK_SIZE = 32;

//const Texture tileset;

struct Chunk
{
    Vector2i position;
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
    std::vector<Object> objects;
    Chunk();
    Chunk(int x, int y);
    void draw(RenderWindow& window, Texture* tileset);
    void generate();
};

#endif // CHUNK_H_INCLUDED
