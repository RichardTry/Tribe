#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "unit_content.h"

class Unit
{
    private:

        sf::Vector2f position;
        unsigned int contentID;
        unsigned int direction;

    public:

        void update(const float & dt, std::vector<UnitContent> & unitlib);
        void render(sf::RenderTarget * target, std::vector<UnitContent> & unitlib);
};

#endif // UNIT_H_INCLUDED
