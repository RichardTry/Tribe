#include "unit.h"
#include "unit_content.h"

void Unit::draw(RenderWindow& window)
{
    RectangleShape unit(Vector2f(unitlib[contentID].spriteSize.x, unitlib[contentID].spriteSize.y));
    unit.setTexture(&unitlib[contentID].texture);
    unit.setPosition(position.x, position.y);
    window.draw(unit);
}
