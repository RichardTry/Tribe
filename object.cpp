#include "object.h"
#include "object_content.h"

Object::Object()
{}

void Object::draw(RenderWindow& window)
{
    RectangleShape object(objlib[contentID].spriteSize);
    object.setTexture(&objlib[contentID].texture);
    object.setOrigin(objlib[contentID].spriteOrigin);
    object.setPosition(position.x, position.y);
    window.draw(object);
}
