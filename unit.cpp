#include "unit.h"

void Unit::update(const float & dt, std::vector<UnitContent> & unitlib)
{

}

void Unit::render(sf::RenderTarget * target, std::vector<UnitContent> & unitlib)
{
    sf::RectangleShape unit(sf::Vector2f(unitlib[contentID].spriteSize.x, unitlib[contentID].spriteSize.y));
    unit.setTexture(&unitlib[contentID].texture);
    unit.setPosition(position.x, position.y);
    target->draw(unit);
}
