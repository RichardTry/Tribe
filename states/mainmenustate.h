#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include "state.h"
#include "mainmenuguistate.h"
#include "gamestate.h"

class MainMenuState : public State
{
    protected:
        void startGameState();

    public:
        MainMenuState(sf::RenderWindow * window, std::stack<State*> * states);
        virtual ~MainMenuState();

        void endState();

        void initGUI();
        void updateInput(const float& dt);
        void update(const float & dt);
        void render(sf::RenderTarget * target = nullptr);
};

#endif // MAINMENUSTATE_H_INCLUDED
