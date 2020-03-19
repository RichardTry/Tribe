#include "chunk.h"
#include <iostream>

sf::Texture tileset;

Chunk::Chunk()
{
}

Chunk::Chunk(int x, int y)
{
    position.x = x;
    position.y = y;
    perlinTest = rand() % 8;
    generated = false;
}

long long coordsToKey(sf::Vector2i coords)
{
    return (((long long)coords.x) << 32) + (long long)coords.y;
}

void Chunk::render(sf::RenderTarget* target)
{
    sf::RectangleShape tile(sf::Vector2f(1, 1));
    tile.setTexture(&tileset);
    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            tile.setPosition(sf::Vector2f(position.x * int(CHUNK_SIZE) + x, position.y * int(CHUNK_SIZE) + y));
            tile.setTextureRect(sf::IntRect(TILE_TEXTURE_SIZE * tiles[x][y].biome, 0, TILE_TEXTURE_SIZE, TILE_TEXTURE_SIZE));
            target->draw(tile);
        }
}

void Chunk::generate(std::unordered_map<long long, Chunk> & world)
{
    perlinVector.x = rand() % 65 - 32;
    perlinVector.y = rand() % 65 - 32;

    long long keyRight = coordsToKey(sf::Vector2i(position.x + 1, position.y));
    long long keyBottom = coordsToKey(sf::Vector2i(position.x, position.y + 1));
    long long keyBottomRight = coordsToKey(sf::Vector2i(position.x + 1, position.y + 1));

    int perlinRight, perlinBottom, perlinBottomRight;

    auto it = world.find(keyRight);
    if (it != world.end())
        perlinRight = (it->second.perlinTest);
    else
    {
        world[keyRight] = Chunk(position.x + 1, position.y);
        perlinRight = world[keyRight].perlinTest;
    }

    it = world.find(keyBottom);
    if (it != world.end())
        perlinBottom = (it->second.perlinTest);
    else
    {
        world[keyBottom] = Chunk(position.x, position.y + 1);
        perlinBottom = world[keyBottom].perlinTest;
    }

    it = world.find(keyBottomRight);
    if (it != world.end())
        perlinBottomRight = (it->second.perlinTest);
    else
    {
        world[keyBottomRight] = Chunk(position.x + 1, position.y + 1);
        perlinBottomRight = world[keyBottomRight].perlinTest;
    }

    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            float tx = float(x) / (CHUNK_SIZE - 1);
            float ty = float(y) / (CHUNK_SIZE - 1);
            uint8_t xTop = perlinTest + tx * (perlinRight - perlinTest);
            uint8_t xBot = perlinBottom + tx * (perlinBottomRight - perlinBottom);
            int res = xTop + ty * (xBot - xTop);
            tiles[x][y].biome = res;
        }

    generated = true;
}
