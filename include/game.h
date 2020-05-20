#ifndef GAME_H
#define GAME_H

#include "content.h"
#include "states/mainmenustate.h"
#include "states/gamestate.h"

class Game
{
    protected:
    //
    sf::RenderWindow * window;
    sf::Event event;

    sf::Clock dtClock;
    float dt;

    Content * content;
    std::stack <State*> states;

    //
    void initWindow();
    void initGUI();
    void initStates();
    void initContent();

    public:
        //
        Game();
        virtual ~Game();

        //
        void updateDt();
        void updateEvents();
        void updateGUI();
        void update();
        void render();
        void run();
};

#endif // GAME_H
