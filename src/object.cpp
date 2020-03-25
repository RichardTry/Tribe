#include "object.h"

Object::Object()
{

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
