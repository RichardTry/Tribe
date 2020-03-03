#include "chunk.h"

void Chunk::draw(RenderWindow& window, Texture* tileset)
{
    RectangleShape tile(Vector2f(1, 1));
    tile.setTexture(tileset);
    for (unsigned int y = 0; y < CHUNK_SIZE; ++y)
        for (unsigned int x = 0; x < CHUNK_SIZE; ++x)
        {
            tile.setPosition(Vector2f(position.x * 32 + x, position.y * 32 + y));
            tile.setTextureRect(IntRect(64, 0, 32, 32));
            window.draw(tile);
        }
}
