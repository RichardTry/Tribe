#include "object.h"
#include "object_content.h"

Object::Object()
{}

void Object::draw(RenderWindow& window)
{
    RectangleShape object(Vector2f(objlib[contentID].visibleSize.x, objlib[contentID].visibleSize.y));
    object.setTexture(&objlib[contentID].texture);
    object.setPosition(position.x, position.y);
    window.draw(object);
}
