#include "object.h"

Object::Object()
{

}

void Object::update(const float & dt, std::vector<ObjectContent> & objlib)
{

}

void Object::render(sf::RenderTarget * target, std::vector<ObjectContent> & objlib)
{
    sf::RectangleShape object(objlib[contentID].spriteSize);
    object.setTexture(&objlib[contentID].texture);
    object.setOrigin(objlib[contentID].spriteOrigin);
    object.setPosition(position.x, position.y);
    target->draw(object);
}
