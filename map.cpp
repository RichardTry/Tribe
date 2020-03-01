#include "map.h"
#include "test_noise.h"

void Map::generate()
{
    height_map[0][0] = 1;
    height_map[MAP_SIZE - 1][0] = 255;
    height_map[MAP_SIZE - 1][MAP_SIZE - 1] = 255;
    height_map[0][MAP_SIZE - 1] = 255;

    fillWithTestNoise(height_map);
}

void Map::draw(RenderWindow& window)
{
    for (unsigned int y = 0; y < MAP_SIZE; ++y)
    {
        for (unsigned int x = 0; x < MAP_SIZE; ++x)
        {
            RectangleShape pixel(Vector2f(1, 1));
            pixel.setPosition(Vector2f(x, y));
            Color lightness(128, 0, 0);
            pixel.setFillColor(lightness);
            window.draw(pixel);
        }
    }
}
