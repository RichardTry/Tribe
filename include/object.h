#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "content.h"

class Object
{
    public:
        sf::Vector2i position;
        std::string contentID;

        Object();

        void update(const float & dt, Content * content);
        void render(sf::RenderTarget * target, Content * content);
};

#endif // OBJECT_H_INCLUDED
