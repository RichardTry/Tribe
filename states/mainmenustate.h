#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include "state.h"
#include "gamestate.h"

class MainMenuState : public State
{
    protected:

    public:
        MainMenuState(sf::RenderWindow * window, std::stack<State*>* states);
        virtual ~MainMenuState();

        void endState();

        void updateInput(const float& dt);
        void update(const float & dt, Content * content);
        void render(sf::RenderTarget * target = nullptr, Content * content = nullptr);
};

#endif // MAINMENUSTATE_H_INCLUDED
