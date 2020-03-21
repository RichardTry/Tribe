#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "chunk.h"
#include "world.h"
#include "object_content.h"
#include "unit_content.h"

class GameState : public State
{
    protected:

        sf::View camera;
        float camera_speed;

        World world;

        void initContent();

    public:
        GameState(sf::RenderWindow * window);
        virtual ~GameState();

        void endState();

        void updateInput(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
