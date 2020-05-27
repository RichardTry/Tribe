#include "mainmenustate.h"

MainMenuState::MainMenuState(sf::RenderWindow * window, std::stack<State*> * states) : State(window, states)
{
    gui.setTarget(*window);
    this->initGUI();
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
    this->render();
    std::cout << "Ending MainMenuState!\n";
}

void MainMenuState::initGUI()
{
    std::vector<std::string> buttons{"Одиночная игра", "Сетевая игра", "Контруктор карт", "Настройки", "Выход"};
    for (int i = 0; i < buttons.size(); ++i)
    {
        sf::String utf8ButtonText = sf::String::fromUtf8(buttons[i].begin(), buttons[i].end());
        tgui::Button::Ptr button = tgui::Button::create(utf8ButtonText);
        std::string toolTipText = "Кнопка\n————\nДелает действие";
        sf::String utf8ToolTipText = sf::String::fromUtf8(toolTipText.begin(), toolTipText.end());
        tgui::Label::Ptr toolTip = tgui::Label::create(utf8ToolTipText);
        gui.add(button);
        button->setToolTip(toolTip);
        button->setPosition(50, 200 + 30 * i);
        button->connect("pressed", std::bind(&MainMenuState::startGameState, this));
    }
}

void MainMenuState::startGameState()
{
    this->states->push(new GameState(this->window, states, "savings/test.save"));
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
}

void MainMenuState::render(sf::RenderTarget * target, Content * content)
{
    gui.draw();
}
