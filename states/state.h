#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <functional>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <TGUI/TGUI.hpp>

class State
{
    protected:
        sf::RenderWindow * window;
        std::stack<State*> * states;
        bool quit;

        sf::Vector2i  mousePositionScreen;
        sf::Vector2i  mousePositionWindow;
        sf::Vector2f  mousePositionView;

    public:
        tgui::Gui gui;

        State(sf::RenderWindow * window, std::stack<State*> * states);
        virtual ~State();

        const bool& getQuit() const;

        virtual void checkForQuit();

        virtual void initGUI() = 0;
        virtual void updateMousePosition();
        virtual void updateInput(const float & dt) = 0;
        virtual void update(const float & dt) = 0;
        virtual void render(sf::RenderTarget * target = nullptr) = 0;
        virtual void endState() = 0;
};

#endif // STATE_H

