#include "content.h"
#include <iostream>

Content::Content()
{

}

Content::~Content()
{
    //dtor
}

void Content::initContent()
{
    //lua experiments
    lua_State* L = luaL_newstate();
    luaL_dostring(L, "x = 42");
    lua_getglobal(L, "x");
    lua_Number x = lua_tonumber(L, 1);
    std::cout << "Lua says: " << (int)x << std::endl;
    lua_close(L);

    std::ifstream iftex("resources/textures.list");
    if (iftex.is_open())
    {
        while(!iftex.eof())
        {
            std::string texture_name, texture_file_name;
            iftex >> texture_name >> texture_file_name;
            if (texture_name == "") std::cout << "WARNING EMPTY FILE!\n";
            texlib[texture_name].loadFromFile("resources/textures/" + texture_file_name);
        }
    }
    iftex.close();

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
}
