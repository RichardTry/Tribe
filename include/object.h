#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "content.h"

class Object
{
    public:
        sf::Vector2i position;
        int rotation;
        std::string contentID;

        Object();
        Object(int x, int y, int rot, std::string ID);

        void update(const float & dt, Content * content);
        void render(sf::RenderTarget * target, Content * content);
};

#endif // OBJECT_H_INCLUDED
