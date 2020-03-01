#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

sf::View camera;

sf::View setCamera(double x, double y)
{
    camera.setCenter(x, y);
    return camera;
}

#endif // VIEW_H_INCLUDED
