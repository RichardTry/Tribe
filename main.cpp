#include "main.h"

int main()
{
    //Создаётся главное окно
    RenderWindow mainWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tribe");

    //Текстура тайлов земли
    if (!tileset.loadFromFile("textures/tileset.png"))
        return EXIT_FAILURE;

    float speed = 1;
    float zoom_speed = 0.1;
    int animslow = 3;
    int8_t dirOfX = 0, dirOfY = 1;
    uint8_t dir = 0;

    //Тестовый объект-здание с тектурой be64.png
    Object a;
    a.visibleSize = Vector2u(2, 2);
    a.position = Vector2i(-3, 4);
    Texture t_a;
    if (!t_a.loadFromFile("textures/be64.png"))
        return EXIT_FAILURE;
    a.texture = t_a;

    //Вектор всех объектов карты
    vector<Object> objects;
    objects.push_back(a);

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

    Clock clock;

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

                case Event::MouseWheelMoved:
                    if(event.mouseWheel.delta == 1 && camera.getSize().y * (1 - zoom_speed) >= 3)
                        camera.zoom(1 - zoom_speed);
                    if(event.mouseWheel.delta == -1 && camera.getSize().y * (1 + zoom_speed) <= 63)
                        camera.zoom(1 + zoom_speed);
                    break;

            }
        }

        float time = clock.getElapsedTime().asSeconds();
        time /= 1200;

        mainWindow.setView(camera);

        mainWindow.clear(Color(0, 0, 128));

        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            camera.move(Vector2f(0, -speed * time * camera.getSize().x));
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            camera.move(Vector2f(-speed * time * camera.getSize().x, 0));
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            camera.move(Vector2f(0, speed * time * camera.getSize().x));
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            camera.move(Vector2f(speed * time * camera.getSize().x, 0));
        }

        float cameraLeft = camera.getCenter().x - camera.getSize().x / 2;
        float cameraRight = camera.getCenter().x + camera.getSize().x / 2;
        float cameraTop = camera.getCenter().y - camera.getSize().y / 2;
        float cameraBottom = camera.getCenter().y + camera.getSize().y / 2;

        for (int y = int(cameraTop) / int(CHUNK_SIZE) - (cameraTop < 0); y <= int(cameraBottom) / int(CHUNK_SIZE) - (cameraBottom < 0); ++y)
        {
            for (int x = int(cameraLeft) / int(CHUNK_SIZE) - (cameraLeft < 0); x <= int(cameraRight) / int(CHUNK_SIZE) - (cameraRight < 0); ++x)
            {
                long long key = (((long long)x) << 32) + (long long)y;
                auto it = world.find(key);
                if (it != world.end())
                {
                    if (!it->second.generated)
                        it->second.generate();
                    it->second.draw(mainWindow);
                }
                else
                {
                    world[key] = Chunk(x, y);
                    world[key].generate();
                    cout << x << "; " << y << " generated!\n";
                }
            }
        }

        for (int s_i = 0; s_i < objects.size(); ++s_i)
            objects[s_i].draw(mainWindow);
        a.draw(mainWindow);

        mainWindow.display();
    }

    return EXIT_SUCCESS;
}
