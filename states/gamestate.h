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

        void initFromSaving(std::string save);

    public:
        GameState(sf::RenderWindow * window, std::string save);
        virtual ~GameState();

        void endState();

        void updateInput(const float & dt);
        void update(const float & dt, Content * content);
        void render(sf::RenderTarget * target = nullptr, Content * content = nullptr);
};

#endif // GAMESTATE_H
