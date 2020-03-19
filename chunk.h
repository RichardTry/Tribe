#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "tile.h"
#include "object.h"
#include "unit.h"

const unsigned int CHUNK_SIZE = 32;

extern sf::Texture tileset;

class Chunk
{
    public:
    sf::Vector2i position;
    sf::Vector2i perlinVector;
    int perlinTest;
    bool generated;
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
    std::vector<Object> objects;
    std::vector<Unit> units;

    Chunk();
    Chunk(int x, int y);

    void update(const float & dt);
    void render(sf::RenderTarget* target);
    void generate(std::unordered_map<long long, Chunk> & world);
};

long long coordsToKey(sf::Vector2i coords);

#endif // CHUNK_H_INCLUDED
