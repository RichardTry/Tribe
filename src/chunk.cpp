#include "chunk.h"
#include <iostream>

Chunk::Chunk()
{
    generated = false;
}

Chunk::Chunk(int x, int y)
{
    position.x = x;
    position.y = y;
    perlinVector.x = rand() % (CHUNK_FACTOR + 1) - CHUNK_FACTOR / 2;
    perlinVector.y = rand() % (CHUNK_FACTOR + 1) - CHUNK_FACTOR / 2;
    generated = false;
}

long long coordsToKey(int x, int y)
{
    return (((long long)x) << 32) + (long long)y;
}

void Chunk::render(sf::RenderTarget * target, Content * content)
{
    sf::RectangleShape tile(sf::Vector2f(1, 1));
    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            tile.setPosition(sf::Vector2f(position.x * int(CHUNK_SIZE) + x, position.y * int(CHUNK_SIZE) + y));
            tile.setTexture(content->tilelib[tiles[x][y].type].texture);
            target->draw(tile);
        }
}

void Chunk::generate(std::unordered_map<long long, Chunk> & world)
{
    long long keyRight = coordsToKey(position.x + 1, position.y);
    long long keyBottom = coordsToKey(position.x, position.y + 1);
    long long keyBottomRight = coordsToKey(position.x + 1, position.y + 1);

    sf::Vector2i perlinVectorRight, perlinVectorBottom, perlinVectorBottomRight;

    auto it = world.find(keyRight);
    if (it != world.end())
        perlinVectorRight = (it->second.perlinVector);
    else
    {
        world[keyRight] = Chunk(position.x + 1, position.y);
        perlinVectorRight = world[keyRight].perlinVector;
    }

    it = world.find(keyBottom);
    if (it != world.end())
        perlinVectorBottom = (it->second.perlinVector);
    else
    {
        world[keyBottom] = Chunk(position.x, position.y + 1);
        perlinVectorBottom = world[keyBottom].perlinVector;
    }

    it = world.find(keyBottomRight);
    if (it != world.end())
        perlinVectorBottomRight = (it->second.perlinVector);
    else
    {
        world[keyBottomRight] = Chunk(position.x + 1, position.y + 1);
        perlinVectorBottomRight = world[keyBottomRight].perlinVector;
    }

    for (uint y = 0; y < CHUNK_SIZE; ++y)
        for (uint x = 0; x < CHUNK_SIZE; ++x)
        {
            int termLeftTop, termLeftBot, termRightBot, termRightTop;
            termLeftTop = perlinVector.x * x + perlinVector.y * y;
            termLeftBot = perlinVectorBottom.x * x + perlinVectorBottom.y * (y - CHUNK_SIZE + 1);
            termRightBot = perlinVectorBottomRight.x * (x - CHUNK_SIZE + 1) + perlinVectorBottomRight.y * (y - CHUNK_SIZE + 1);
            termRightTop = perlinVectorRight.x * (x - CHUNK_SIZE + 1) + perlinVectorRight.y * y;

            float tx = float(x) / (CHUNK_SIZE - 1);
            float ty = float(y) / (CHUNK_SIZE - 1);
            int xTop = termLeftTop + tx * (termRightTop - termLeftTop);
            int xBot = termLeftBot + tx * (termRightBot - termLeftBot);
            int res = xTop + ty * (xBot - xTop);
            res = std::min(std::max(0, res / 2), 8);
            if (res == 0) tiles[x][y].type = "water";
            if (res == 1)
            {
                tiles[x][y].type = "sand";
                if (rand() % 20 == 0) objects.push_back(Object(position.x * CHUNK_SIZE + x, position.y * CHUNK_SIZE + y, 0, "palm1"));
            }
            if (res == 2) tiles[x][y].type = "wet_grass";
            if (res == 3) tiles[x][y].type = "dry_grass";
            if (res == 4) tiles[x][y].type = "sand";
            if (res == 5) tiles[x][y].type = "grass";
            if (res == 6)
            {
                tiles[x][y].type = "cold_grass";
                if (rand() % 5 == 0) objects.push_back(Object(position.x * CHUNK_SIZE + x, position.y * CHUNK_SIZE + y, 0, "tree1"));
            }
            if (res == 7) tiles[x][y].type = "ice_grass";
            if (res == 8) tiles[x][y].type = "snow";
        }
    generated = true;
}
