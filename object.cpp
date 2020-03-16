#include "object.h"

Object::Object()
{}

void Object::draw(RenderWindow& window)
{
    RectangleShape object(Vector2f(visibleSize.x, visibleSize.y));
    object.setTexture(&texture);
    object.setPosition(position.x, position.y);
    window.draw(object);
}
