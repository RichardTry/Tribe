#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <SFML/System/Vector2.hpp>
sf::View camera;

sf::View setCamera(Vector2i center)
{
    camera.setCenter(center.x, center.y);
    return camera;
}

#endif // VIEW_H_INCLUDED
