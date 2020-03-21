#include "mainmenustate.h"

MainMenuState::MainMenuState(sf::RenderWindow * window) : State(window)
{

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState!\n";
}

void MainMenuState::updateInput(const float & dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "A\n";
    }
}

void MainMenuState::update(const float & dt)
{
    updateMousePosition();
    this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget * target)
{

}
