#include "state.h"

State::State(sf::RenderWindow * window, std::stack<State*>* states)
{
    this->window = window;
    this->quit = false;
}

State::~State()
{
    //dtor
}

const bool & State::getQuit() const
{
    return this->quit;
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

void State::updateMousePosition()
{
    mousePositionScreen = sf::Mouse::getPosition();
    mousePositionWindow = sf::Mouse::getPosition(*window);
    mousePositionView = window->mapPixelToCoords(mousePositionWindow);
}
