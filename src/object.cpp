#include "object.h"

Object::Object()
{

}

Object::Object(int x, int y, std::string ID)
{
    position = sf::Vector2i(x, y);
    contentID = ID;
}

void Object::update(const float & dt, Content * content)
{

}

void Object::render(sf::RenderTarget * target, Content * content)
{
    sf::RectangleShape object(content->objlib[contentID].spriteSize);
    object.setTexture(content->objlib[contentID].texture);
    object.setOrigin(content->objlib[contentID].spriteOrigin);
    object.setPosition(position.x, position.y);
    target->draw(object);
}
