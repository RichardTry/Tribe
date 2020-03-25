#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>

#include "chunk.h"
#include "content.h"

class World
{
    private:
        sf::Texture tileset;
        std::unordered_map<long long, Chunk> world;

        void initWorld();

    protected:

    public:
        World();
        virtual ~World();

        void addObject(int x, int y, Object & obj);

        void update(const float & dt);
        void render(sf::RenderTarget * target, Content * content, sf::View * view);
};

#endif // WORLD_H
