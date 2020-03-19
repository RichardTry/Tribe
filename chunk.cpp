#include "chunk.h"
#include <iostream>

Texture tileset;

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

void Chunk::render(sf::RenderTarget& target)
{
    RectangleShape tile(Vector2f(1, 1));
    tile.setTexture(&tileset);
    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            tile.setPosition(Vector2f(position.x * int(CHUNK_SIZE) + x, position.y * int(CHUNK_SIZE) + y));
            tile.setTextureRect(IntRect(TILE_TEXTURE_SIZE * tiles[x][y].biome, 0, TILE_TEXTURE_SIZE, TILE_TEXTURE_SIZE));
            target.draw(tile);
        }
}

void Chunk::generate(std::unordered_map<long long, Chunk> & world)
{
    perlinVector.x = rand() % 65 - 32;
    perlinVector.y = rand() % 65 - 32;

    long long keyRight = coordsToKey(Vector2i(position.x + 1, position.y));
    long long keyBottom = coordsToKey(Vector2i(position.x, position.y + 1));
    long long keyBottomRight = coordsToKey(Vector2i(position.x + 1, position.y + 1));

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

    for (int i = 0; i < 50; ++i){
    Object o;
    o.contentID = 0;
    o.position = Vector2i(position.x * CHUNK_SIZE + rand() % CHUNK_SIZE, position.y * CHUNK_SIZE + rand() % CHUNK_SIZE);
    objects.push_back(o);
    }

    Unit u;
    u.contentID = 0;
    u.position = Vector2f(position.x * CHUNK_SIZE + rand() % CHUNK_SIZE, position.y * CHUNK_SIZE + rand() % CHUNK_SIZE);
    units.push_back(u);

    generated = true;
}
