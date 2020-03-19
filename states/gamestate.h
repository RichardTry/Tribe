#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "chunk.h"

class GameState : public State
{
    protected:


    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        void endState();

        void updateKeybinds(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
