#include "gamestate.h"

GameState::GameState(sf::RenderWindow * window) : State(window)
{
    this->initContent();
}

GameState::~GameState()
{

}

void GameState::initContent()
{
    camera.setCenter(sf::Vector2f(0.0, 0.0));
    camera.setSize(sf::Vector2f(window->getSize()));
    camera.zoom(0.05);
    camera_speed = 20;
}

void GameState::endState()
{
    std::cout << "Ending GameState!\n";
}

void GameState::updateInput(const float & dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        camera.move(0, -camera_speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        camera.move(-camera_speed * dt, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        camera.move(0, camera_speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        camera.move(camera_speed * dt, 0);
    }
}

void GameState::update(const float & dt)
{
    updateMousePosition();
    this->updateInput(dt);
}

void GameState::render(sf::RenderTarget * target)
{
    target->setView(camera);
    world.render(target, &camera);
}
