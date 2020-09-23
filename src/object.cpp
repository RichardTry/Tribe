#include "object.h"

Object::Object()
{

}

Object::Object(int x, int y, int rot, std::string ID)
{
    position = sf::Vector2i(x, y);
    rotation = rot;
    contentID = ID;
}

void Object::update(const float & dt, Content * content)
{

}

void Object::render(sf::RenderTarget * target, Content * content)
{
    sf::RectangleShape object(content->objlib[contentID].spriteSize);
    switch (rotation % 4)
    {
        case 0:
            object.setTexture(content->objlib[contentID].texture_up);
            break;
        case 1:
            object.setTexture(content->objlib[contentID].texture_right);
            break;
        case 2:
            object.setTexture(content->objlib[contentID].texture_down);
            break;
        case 3:
            object.setTexture(content->objlib[contentID].texture_left);
            break;
        default:
            object.setTexture(content->objlib[contentID].texture_up);
            break;
    }
    object.setOrigin(content->objlib[contentID].spriteOrigin);
    object.setPosition(position.x, position.y);
    target->draw(object);
}

