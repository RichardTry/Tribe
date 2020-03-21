#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>

#include "chunk.h"

class World
{
    private:
        sf::Texture tileset;
        std::unordered_map<long long, Chunk> world;
        std::vector<ObjectContent> objlib;
        std::vector<UnitContent> unitlib;

        void initWorld();

    protected:

    public:
        World();
        virtual ~World();

        void update(const float & dt);
        void render(sf::RenderTarget * target, sf::View * view);
};

#endif // WORLD_H
