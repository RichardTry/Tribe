#ifndef TEST_NOISE_H_INCLUDED
#define TEST_NOISE_H_INCLUDED

#include "map.h"
#include <math.h>

void fillWithTestNoise(uint8_t (&height_map)[MAP_SIZE][MAP_SIZE])
{
    for (int i = MAP_MULT - 1; i >= 0; --i)
    {
        int prevXDiv = 0, prevYDiv = 0;
        int bias = rand() % 2 * pow(2, i);
        for (int x = 0; x < MAP_SIZE; ++x)
            for (int y = 0; y < MAP_SIZE; ++y)
            {
                int xDiv = x / pow(2, i), yDiv = y / pow(2,i);
                if (xDiv != prevXDiv || yDiv != prevYDiv)
                    bias = rand() % 2 * pow(2, i);
                height_map[x][y] += bias;
                prevXDiv = xDiv;
                prevYDiv = yDiv;
            }
    }
}

#endif // TEST_NOISE_H_INCLUDED
