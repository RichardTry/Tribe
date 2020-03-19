#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "object_content.h"

class Object
{
    private:
        sf::Vector2i position;
        unsigned int contentID;

    public:

        Object();

        void update(const float & dt, std::vector<ObjectContent> & objlib);
        void render(sf::RenderTarget * target, std::vector<ObjectContent> & objlib);
};

#endif // OBJECT_H_INCLUDED
