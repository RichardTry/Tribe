#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "state.h"

class MainMenuState : public State
{
    protected:


    public:
        MainMenuState(sf::RenderWindow * window);
        virtual ~MainMenuState();

        void endState();

        void updateInput(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};

#endif // MAINMENUSTATE_H_INCLUDED
