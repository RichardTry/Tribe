#include "chunk.h"

Texture tileset;

std::unordered_map<long long, Chunk> world;

Chunk::Chunk()
{
}

Chunk::Chunk(int x, int y)
{
    position.x = x;
    position.y = y;
    uint8_t biome = rand() % 8;
    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            tiles[x][y].biome = biome;
        }
}

void Chunk::draw(RenderWindow& window)
{
    RectangleShape tile(Vector2f(1, 1));
    tile.setTexture(&tileset);
    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            tile.setPosition(Vector2f(position.x * int(CHUNK_SIZE) + x, position.y * int(CHUNK_SIZE) + y));
            tile.setTextureRect(IntRect(32 * tiles[x][y].biome, 0, 32, 32));
            window.draw(tile);
        }
}

void Chunk::generate()
{
    for (uint8_t y = 0; y < CHUNK_SIZE; ++y)
        for (uint8_t x = 0; x < CHUNK_SIZE; ++x)
        {
            tiles[x][y].biome = int(x * y * 8) / CHUNK_SIZE / CHUNK_SIZE;
        }
}
