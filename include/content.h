#ifndef CONTENT_H
#define CONTENT_H

#include <unordered_map>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "object_content.h"
#include "unit_content.h"

class Content
{
    public:

        std::unordered_map <std::string, sf::Texture> texlib;
        std::unordered_map <std::string, ObjectContent> objlib;
        std::unordered_map <std::string, UnitContent> unitlib;

        Content();
        virtual ~Content();

        void initContent();
};

#endif // CONTENT_H
