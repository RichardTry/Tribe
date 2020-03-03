#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

#include "map.h"
#include "chunk.h"
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

    //Текстура тайлов земли
    Texture tileset;
    if (!tileset.loadFromFile("textures/tileset.png"))
        return EXIT_FAILURE;

    //Игровой объект тестового персонажа
    Object b;
    b.position.x = 0;
    b.position.y = 0;

    float speed = 0.001;
    int animslow = 3;
    int8_t dirOfX = 0, dirOfY = 1;
    uint8_t dir = 0;

    //Тестовый объект-здание с тектурой be64.png
    Object a;
    a.visibleSize = Vector2u(2, 2);
    a.position = Vector2i(3, 4);
    Texture t_a;
    if (!t_a.loadFromFile("textures/be64.png"))
        return EXIT_FAILURE;
    a.texture = t_a;

    //Вектор всех объектов карты
    vector<Object> objects;
    objects.push_back(a);
    objects.push_back(b);

    //Создание и рандомное размещение тестовых объектов-зданий
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        Object o;
        o.visibleSize = Vector2u(2, 2);
        o.position = Vector2i(rand() % 50, rand() % 50);
        o.texture = t_a;
        objects.push_back(o);
    }

    //Объект карты и её первоначальная генерация
    Chunk ch1, ch2;
    ch1.position = Vector2u(0, 0);
    ch2.position = Vector2u(1, 0);
    //ch.generate();

    camera.setSize(16, 9);
    camera.setCenter(0,0);

    uint windowWidth = SCREEN_WIDTH, windowHeight = SCREEN_HEIGHT;

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
                    camera.setSize(camera.getSize().x / windowWidth * event.size.width, camera.getSize().y / windowHeight * event.size.height);
                    windowWidth = event.size.width;
                    windowHeight = event.size.height;
                    break;
            }
        }

        mainWindow.setView(camera);
        mainWindow.clear(Color(0, 0, 128));

        if(Keyboard::isKeyPressed(Keyboard::Q))
            camera.zoom(0.99);
        if(Keyboard::isKeyPressed(Keyboard::E))
            camera.zoom(1.01);

        bool ispr = false;
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            camera.move(Vector2f(0, -speed * camera.getSize().x));
            dirOfY = -1;
            if(!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
                dirOfX = 0;
            ispr = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            camera.move(Vector2f(-speed * camera.getSize().x, 0));
            dirOfX = -1;
            if(!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S))
                dirOfY = 0;
            ispr = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            camera.move(Vector2f(0, speed * camera.getSize().x));
            dirOfY = 1;
            if(!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
                dirOfX = 0;
            ispr = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            camera.move(Vector2f(speed * camera.getSize().x, 0));
            dirOfX = 1;
            if(!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S))
                dirOfY = 0;
            ispr = true;
        }

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

        ch1.draw(mainWindow, &tileset);
        ch2.draw(mainWindow, &tileset);

        for (int s_i = 0; s_i < objects.size(); ++s_i)
            objects[s_i].draw(mainWindow);
        a.draw(mainWindow);

        mainWindow.display();
    }

    return EXIT_SUCCESS;
}
