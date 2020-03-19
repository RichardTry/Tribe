#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

const unsigned int TILE_TEXTURE_SIZE = 256;

struct Tile
{
    unsigned int height;
    unsigned int biome;
    unsigned int soil;
};

#endif // TILE_H_INCLUDED
