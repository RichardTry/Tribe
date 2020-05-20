#include "mainmenustate.h"

MainMenuState::MainMenuState(sf::RenderWindow * window, std::stack<State*>* states) : State(window, states)
{

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
    this->render();
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

void MainMenuState::update(const float & dt, Content * content)
{
    updateMousePosition();
    this->updateInput(dt);

    ImGui::Begin("Sosat!");
        if (ImGui::Button("Start game"))
        {
            states->push(new GameState(this->window, states, "savings/test.save"));
        }
        if (ImGui::Button("Quit"))
        {
            quit = true;
        }
    ImGui::End();
}

void MainMenuState::render(sf::RenderTarget * target, Content * content)
{
    ImGui::SFML::Render(*target);
}
