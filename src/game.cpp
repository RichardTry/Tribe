#include "game.h"

void Game::initWindow()
{
    /* Creates a SFML window using options from a window.ini file */

    std::ifstream ifs("config/window.ini");

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

void Game::initGUI()
{
    ImGui::SFML::Init(*window);
}

void Game::initStates()
{
    //this->states.push(new GameState(this->window, "savings/test.save"));
    this->states.push(new MainMenuState(this->window, &this->states));
}

void Game::initContent()
{
    content = new Content();
    content->initContent();
}

Game::Game()
{
    this->initWindow();
    this->initGUI();
    this->initStates();
    this->initContent();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
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
                ImGui::SFML::ProcessEvent(this->event);

                if (this->event.type == sf::Event::Closed)
                    this->window->close();
        }
}

void Game::updateGUI()
{
    ImGui::SFML::Update(*window, dtClock.restart());
}

void Game::update()
{
    updateDt();
    updateEvents();
    updateGUI();

    if (!states.empty())
    {
        states.top()->update(dt, content);


        if (states.top()->getQuit())
        {
            states.top()->endState();
            delete states.top();
            states.pop();
        }
    }

    // Application end
    else
    {
        ImGui::SFML::Shutdown();
        window->close();
    }
}

void Game::render()
{
    window->clear();

    if (!states.empty())
        states.top()->render(window, content);

    window->display();
}

void Game::run()
{
    while (window->isOpen())
    {
        update();
        render();
    }
}
