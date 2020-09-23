#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "content.h"
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
        Content content;
        Object on_cursor;

        void initFromSaving(std::string save);

    public:
        GameState(sf::RenderWindow * window, std::stack<State*> * states, std::string save);
        virtual ~GameState();

        void initGUI();

        void endState();

        void updateInput(const float & dt);
        void updateOnCursorObject();
        void update(const float & dt);
        void render(sf::RenderTarget * target = nullptr);
};

#endif // GAMESTATE_H

