#include "gamestate.h"

GameState::GameState(sf::RenderWindow * window, std::string save) : State(window)
{
    this->initFromSaving(save);
}

GameState::~GameState()
{

}

void GameState::initFromSaving(std::string save)
{
    camera.setSize(sf::Vector2f(window->getSize()));

    std::ifstream ifs(save);

    sf::Vector2f cameraCenter;
    float zoom;

    if (ifs.is_open())
    {
        ifs >> cameraCenter.x >> cameraCenter.y;
        ifs >> zoom;
        ifs >> camera_speed;

        std::string curstr;
        ifs >> curstr;

        // Objects init
        while (curstr != "<units>")
        {
            int x, y;
            ifs >> x >> y;

            ifs >> curstr;
            if (curstr == "<objects>")
            {
                ifs >> curstr;
                while (curstr != "</objects>")
                {
                    Object obj;
                    obj.contentID = curstr;
                    ifs >> obj.position.x >> obj.position.y;
                    world.addObject(x, y, obj);
                    ifs >> curstr;
                }
            }
            ifs >> curstr;
        }
    }

    ifs.close();

    camera.setCenter(cameraCenter);
    camera.zoom(zoom);
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

void GameState::update(const float & dt, Content * content)
{
    updateMousePosition();
    this->updateInput(dt);
}

void GameState::render(sf::RenderTarget * target, Content * content)
{
    target->setView(camera);
    world.render(target, content, &camera);
}
