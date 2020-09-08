#include "world.h"

World::World()
{
    srand(time(0));
    initWorld();
}

World::~World()
{
    //dtor
}

void World::initWorld()
{

}

void World::addObject(int x, int y, Object & obj)
{
    world[coordsToKey(x, y)].objects.push_back(obj);
}

void World::update(const float & dt)
{

}

void World::render(sf::RenderTarget * target, Content * content, sf::View * view)
{
    for (int y = floor(view->getCenter().y / CHUNK_SIZE) - 2; y <= floor(view->getCenter().y / CHUNK_SIZE) + 2; ++y)
    {
        for (int x = floor(view->getCenter().x / CHUNK_SIZE) - 2; x <= floor(view->getCenter().x / CHUNK_SIZE) + 2; ++x)
        {
            long long key = coordsToKey(x, y);
            auto it = world.find(key);
            if (it == world.end())  world[key] = Chunk(x, y);
            if (!world[key].generated)
                    world[key].generate(world);
            world[key].render(target, content);

            for (auto & obj : world[key].objects)
            {
                obj.render(target, content);
            }
        }
    }
}
