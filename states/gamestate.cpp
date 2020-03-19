#include "gamestate.h"

GameState::GameState(sf::RenderWindow * window) : State(window)
{
    this->world = new std::unordered_map<long long, Chunk>();
    this->initContent();
}

GameState::~GameState()
{
    delete world;
}

void GameState::initContent()
{
    camera.setCenter(sf::Vector2f(0.0, 0.0));
    camera.setSize(sf::Vector2f(window->getSize()));
}

void GameState::endState()
{
    std::cout << "Ending GameState!\n";
}

void GameState::updateInput(const float & dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "A\n";
    }
}

void GameState::update(const float & dt)
{
    this->updateInput(dt);
}

void GameState::render(sf::RenderTarget * target)
{
    target->setView(camera);

    for (int y = 0; y <= 0; ++y)
        {
            for (int x = 0; x <= 0; ++x)
            {
                long long key = coordsToKey(sf::Vector2i(x, y));
                auto it = world->find(key);
                if (it != world->end())
                {
                    if (!it->second.generated)
                        it->second.generate(*world);
                }
                else
                {
                    (*world)[key] = Chunk(x, y);
                    (*world)[key].generate(*world);
                }
                (*world)[key].render(target);
            }
        }
}
