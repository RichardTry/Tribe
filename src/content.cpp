#include "content.h"
#include <iostream>

std::string Content::current_mod = "";

std::unordered_map <std::string, sf::Texture> Content::texlib;
std::unordered_map <std::string, TileContent> Content::tilelib;
std::unordered_map <std::string, ObjectContent> Content::objlib;
std::unordered_map <std::string, UnitContent> Content::unitlib;

Content::Content()
{

}

Content::~Content()
{
    //dtor
}

int Content::register_tile(lua_State * L)
{
    std::string name = luaL_checkstring(L, 1);
    lua_getfield(L, 2, "texture");
    std::string texture = luaL_checkstring(L, -1);
    std::cout << name << std::endl;
    tilelib[name].texture = new sf::Texture();
    tilelib[name].texture->loadFromFile("mods/" + current_mod + "/textures/" + texture);
    std::cout << texture << std::endl;
    return 1;
}

void Content::initContent(std::string save)
{
    std::ifstream ifmods("save/" + save + "/mods.txt");
    if (ifmods.is_open())
    {
        while(ifmods >> current_mod)
        {
            if (current_mod == "")
            {
                std::cout << "Warning: saving with zero mods\n";
                break;
            }

            lua_State * L = luaL_newstate();
            lua_register(L, "register_tile", Content::register_tile);
            //lua_pushcfunction(L, Content::register_tile);
            //lua_setglobal(L, "register_tile");
            std::string lua_file = "mods/" + current_mod + "/init.lua";
            int ok = luaL_dofile(L, lua_file.c_str());
            if (ok != LUA_OK)
                std::cout << "Error at loading " << current_mod << " mod!\n";
            else
                std::cout << current_mod << " mod loaded.\n";
            lua_close(L);

        }
    }
    ifmods.close();
    /*
    std::ifstream ifobj("resources/objects.list");
    if (ifobj.is_open())
    {
        while (!ifobj.eof())
        {
            std::string object_name, object_texture_name;
            ifobj >> object_name >> object_texture_name;
            if (object_name == "") std::cout << "WARNING EMPTY FILE!\n";
            objlib[object_name].texture = &texlib[object_texture_name];
            ifobj >> objlib[object_name].spriteSize.x >> objlib[object_name].spriteSize.y;
            ifobj >> objlib[object_name].spriteOrigin.x >> objlib[object_name].spriteOrigin.y;
        }
    }

    ifobj.close();
    */
}
