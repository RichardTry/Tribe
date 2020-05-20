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

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "content.h"
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

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
        State(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~State();

        const bool& getQuit() const;

        virtual void checkForQuit();

        virtual void endState() = 0;
        virtual void updateMousePosition();
        virtual void updateInput(const float & dt) = 0;
        virtual void update(const float & dt, Content * content) = 0;
        virtual void render(sf::RenderTarget * target = nullptr, Content * content = nullptr) = 0;
};

#endif // STATE_H
