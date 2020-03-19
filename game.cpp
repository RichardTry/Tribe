#include "game.h"

void Game::initWindow()
{
    /* Creates a SFML window using options from a window.ini file */

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_boubds(1120, 630);
    unsigned frame_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_boubds.width >> window_boubds.height;
        ifs >> frame_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_boubds, title);
    this->window->setFramerateLimit(frame_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

void Game::updateDt()
{
    /* Updates the dt variable with the time it takes to update and render one frame.*/
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateEvents()
{
        while (this->window->pollEvent(this->event))
        {
                if (this->event.type == sf::Event::Closed)
                    this->window->close();
        }
}

void Game::update()
{
    this->updateEvents();
}

void Game::render()
{
    this->window->clear();
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
