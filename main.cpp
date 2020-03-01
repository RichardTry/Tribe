#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

#include "map.h"
#include "object.h"
#include "view.h"

using namespace sf;
using namespace std;

const int SCREEN_WIDTH = 1120;
const int SCREEN_HEIGHT = 630;

int main()
{
    //Создаётся главное окно
    RenderWindow mainWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tribe");

    //Тектура тестового персонажа
    Texture t_human;
    if (!t_human.loadFromFile("textures/8-direction-movement.png"))
        return EXIT_FAILURE;

    //Спрайт тестового персонажа и установка в него текстуры
    Sprite s_human;
    s_human.setTexture(t_human);

    uint tile = 0;

    //Спрайт тайлов земли и загрузка текстуры-индикатора высоты
    Texture t_land;
    if (!t_land.loadFromFile("textures/height-line.png"))
        return EXIT_FAILURE;
    Sprite s_land;
    s_land.setTexture(t_land);

    //Игровой объект тестового персонажа
    Object b;
    b.x = 0;
    b.y = 0;

    int speed = 1;
    int animslow = 3;
    int8_t dirOfX = 0, dirOfY = 1;
    uint8_t dir = 0;

    //Тестовый объект-здание с тектурой be64.png
    Object a;
    a.x = 300;
    a.y = 400;
    Texture t_a;
    if (!t_a.loadFromFile("textures/be64.png"))
        return EXIT_FAILURE;
    a.setTexture(t_a);

    //Вектор всех объектов карты
    vector<Object> objects;
    objects.push_back(a);
    objects.push_back(b);

    //Создание и рандомное размещение тестовых объектов-зданий
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        Object o;
        o.x = rand() % 50;
        o.y = rand() % 50;
        o.setTexture(t_a);
        objects.push_back(o);
    }

    //Объект карты и её первоначальная генерация
    Map m;
    m.generate();

    camera.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (mainWindow.isOpen())
    {
        Event event;
        while (mainWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    mainWindow.close();
                    break;

                case Event::Resized:
                    FloatRect visibleArea (b.x, b.y, event.size.width, event.size.height);
                    break;
            }
        }

        //mainWindow.setView(View(visible));
        mainWindow.clear(Color(0, 0, 128));

        if(Keyboard::isKeyPressed(Keyboard::Q))
            camera.zoom(0.9);
        if(Keyboard::isKeyPressed(Keyboard::E))
            camera.zoom(1.1);

        s_human.setPosition(b.x, b.y);
        bool ispr = false;
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            b.y -= speed;
            dirOfY = -1;
            if(!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
                dirOfX = 0;
            tile++;
            ispr = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            b.x -= speed;
            dirOfX = -1;
            if(!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S))
                dirOfY = 0;
            tile++;
            ispr = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            b.y += speed;
            dirOfY = 1;
            if(!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
                dirOfX = 0;
            tile++;
            ispr = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            b.x += speed;
            dirOfX = 1;
            if(!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S))
                dirOfY = 0;
            tile++;
            ispr = true;
        }


        if (!(tile % 8 == 1 || tile % 8 == 5) && !ispr)
            tile++;

        if (dirOfX == -1 && dirOfY == 1)
            dir = 0;
        if (dirOfX == 0 && dirOfY == 1)
            dir = 1;
        if (dirOfX == 1 && dirOfY == 1)
            dir = 2;
        if (dirOfX == -1 && dirOfY == 0)
            dir = 3;
        if (dirOfX == 1 && dirOfY == 0)
            dir = 4;
        if (dirOfX == -1 && dirOfY == -1)
            dir = 5;
        if (dirOfX == 0 && dirOfY == -1)
            dir = 6;
        if (dirOfX == 1 && dirOfY == -1)
            dir = 7;

        s_human.setTextureRect(IntRect((tile / animslow % 8) * 60, dir * 110, 60, 110));

        for (int y = 0; y < MAP_SIZE; ++y)
            for (int x = 0; x < MAP_SIZE; ++x)
            {
                s_land.setTextureRect(IntRect(m.height_map[x][y], 0, 1, 1));
                s_land.setPosition(x * 32, y * 32);
                s_land.setScale(32, 32);
                mainWindow.draw(s_land);
            }

        for (int s_i = 0; s_i < objects.size(); ++s_i)
            objects[s_i].draw(mainWindow);
        mainWindow.draw(a.sprite);
        mainWindow.draw(s_human);
        mainWindow.display();
    }

    return EXIT_SUCCESS;
}
