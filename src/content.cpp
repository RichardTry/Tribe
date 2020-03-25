#include "content.h"

Content::Content()
{
    initContent();
}

Content::~Content()
{
    //dtor
}

void Content::initContent()
{
    std::ifstream iftex("resources/textures.list");
    if (iftex.is_open())
    {
        std::string texture_name, texture_file_name;
        iftex >> texture_name >> texture_file_name;
        //sf::Texture tex;
        //texlib[texture_name] = tex;
        texlib[texture_name].loadFromFile("resources/textures/" + texture_file_name);
    }
    iftex.close();

    std::ifstream ifobj("resources/objects.list");
    if (ifobj.is_open())
    {
        std::string object_name, object_texture_name;
        ifobj >> object_name >> object_texture_name;
        objlib[object_name].texture = &texlib[object_texture_name];
        ifobj >> objlib[object_name].spriteSize.x >> objlib[object_name].spriteSize.y;
        ifobj >> objlib[object_name].spriteOrigin.x >> objlib[object_name].spriteOrigin.y;
    }
    ifobj.close();
}
