#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "tile.h"
#include "object.h"

const unsigned int CHUNK_SIZE = 32;

extern Texture tileset;

struct Chunk
{
    Vector2i position;
    Vector2i perlinVector;
    int perlinTest;
    bool generated;
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
    std::vector<Object> objects;
    Chunk();
    Chunk(int x, int y);
    void draw(RenderWindow& window);
    void generate();
};

long long coordsToKey(Vector2i coords);

extern std::unordered_map<long long, Chunk> world;

#endif // CHUNK_H_INCLUDED
