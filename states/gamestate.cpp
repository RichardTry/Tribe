#include "gamestate.h"

GameState::GameState(sf::RenderWindow * window, std::stack<State*> * states, std::string save) : State(window, states)
{
    gui.setTarget(*window);
    this->initGUI();
    this->content.initContent(save);
    this->initFromSaving(save);

    on_cursor.contentID = "head";
}

GameState::~GameState()
{

}

void GameState::initGUI(){}

void GameState::initFromSaving(std::string save)
{
    camera.setSize(sf::Vector2f(window->getSize()));

    std::ifstream ifs("save/" + save + "/save");

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        on_cursor.contentID = "";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        on_cursor.rotation++;
    }
}

void GameState::updateOnCursorObject()
{
    on_cursor.position = sf::Vector2i(mousePositionView);
}

void GameState::update(const float & dt)
{
    updateMousePosition();
    updateOnCursorObject();
    this->updateInput(dt);
}

void GameState::render(sf::RenderTarget * target)
{
    target->setView(camera);
    world.render(target, &content, &camera);
    if (on_cursor.contentID != "") on_cursor.render(target, &content);
}

