#ifndef GAME_H
#define GAME_H

#include "gamestate.h"

class Game
{
    private:
    //
    sf::RenderWindow *window;
    sf::Event event;

    sf::Clock dtClock;
    float dt;

    std::stack <State*> states;

    //
    void initWindow();
    void initStates();

    public:
        //
        Game();
        virtual ~Game();

        //
        void updateDt();
        void updateEvents();
        void update();
        void render();
        void run();
};

#endif // GAME_H
