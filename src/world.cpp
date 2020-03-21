#include "world.h"

World::World()
{
    initWorld();
}

World::~World()
{
    //dtor
}

void World::initWorld()
{
    tileset.loadFromFile("resources/textures/tileset-hd.png");
}

void World::update(const float & dt)
{

}

void World::render(sf::RenderTarget * target, sf::View * view)
{
    //std::cout << view->getCenter().x << ", " << view->getCenter().y << std::endl;
    for (int y = floor(view->getCenter().y / CHUNK_SIZE) - 2; y <= floor(view->getCenter().y / CHUNK_SIZE) + 2; ++y)
        {
            for (int x = floor(view->getCenter().x / CHUNK_SIZE) - 2; x <= floor(view->getCenter().x / CHUNK_SIZE) + 2; ++x)
            {
                long long key = coordsToKey(sf::Vector2i(x, y));
                auto it = world.find(key);
                if (it != world.end())
                {
                    if (!it->second.generated)
                        it->second.generate(world);
                }
                else
                {
                    world[key] = Chunk(x, y);
                    world[key].generate(world);
                }
                world[key].render(target, &tileset);
            }
        }
}
