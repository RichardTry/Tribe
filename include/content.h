#ifndef CONTENT_H
#define CONTENT_H

#include <unordered_map>
#include <fstream>
#include <functional>
#include <SFML/Graphics.hpp>

#include "tile.h"
#include "object_content.h"
#include "unit_content.h"
#include "lua/include/lua.hpp"

class Content
{
    private:
        static int register_tile(lua_State * L);

    public:
        std::unordered_map <std::string, sf::Texture> texlib;
        std::unordered_map <std::string, Tile> tilelib;
        std::unordered_map <std::string, ObjectContent> objlib;
        std::unordered_map <std::string, UnitContent> unitlib;

        Content();
        virtual ~Content();

        void initContent(std::string save);
};

#endif // CONTENT_H
