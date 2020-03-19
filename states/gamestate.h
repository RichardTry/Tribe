#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "chunk.h"
#include "object_content.h"
#include "unit_content.h"

class GameState : public State
{
    protected:

        sf::View camera;

        sf::Texture tileset;
        std::unordered_map<long long, Chunk> * world;
        std::vector<ObjectContent> objlib;
        std::vector<UnitContent> unitlib;

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
