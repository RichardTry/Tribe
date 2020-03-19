#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
    //ctor
}

GameState::~GameState()
{
    //dtor
}

void GameState::endState()
{
    std::cout << "Ending GameState!\n";
}

void GameState::updateKeybinds(const float& dt)
{
    this->checkForQuit();
}

void GameState::update(const float& dt)
{
    this->updateKeybinds(dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "A\n";
    }
}

void GameState::render(sf::RenderTarget* target)
{

}
