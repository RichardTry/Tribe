#include "main.h"
#include "game.h"

int main()
{

    Game game;
    game.run();

    /*

    //Создаётся главное окно
    RenderWindow mainWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tribe");

    //Текстура тайлов земли
    if (!tileset.loadFromFile("textures/tileset-hd.png"))
        return EXIT_FAILURE;

    float speed = 1;
    float zoom_speed = 0.1;

    //Тестовый объект-здание с тектурой be64.png
    //ObjectContent objlib[1];
    Init();

    vector<int> arofvec [10];

    Texture selection_t;
    if (!selection_t.loadFromFile("textures/selection.png"))
        return EXIT_FAILURE;

    Texture t_a;
    if (!t_a.loadFromFile("textures/treesprite.png"))
        return EXIT_FAILURE;
    objlib[0].texture = t_a;

    Texture u_a;
    if (!t_a.loadFromFile("textures/unit.png"))
        return EXIT_FAILURE;
    unitlib[0].texture = u_a;

    Clock clock;

    uint windowWidth = SCREEN_WIDTH, windowHeight = SCREEN_HEIGHT;

    Object* o_selected;

    while (mainWindow.isOpen())
    {
        bool isClicked = false;
        Vector2i pixel = Mouse::getPosition(mainWindow);
        Vector2f pos = mainWindow.mapPixelToCoords(pixel);
        Vector2i mappos = Vector2i(floor(pos.x), floor(pos.y));

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
                    if (event.mouseWheel.delta == 1 && camera.getSize().y * (1 - zoom_speed) >= 3)
                        camera.zoom(1 - zoom_speed);
                    if (event.mouseWheel.delta == -1 && camera.getSize().y * (1 + zoom_speed) <= 63)
                        camera.zoom(1 + zoom_speed);
                    break;
                case Event::MouseButtonPressed:
                    if (event.key.code == Mouse::Left)
                        isClicked = true;
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

        for (int y = floor(cameraTop / int(CHUNK_SIZE)); y <= floor(cameraBottom / int(CHUNK_SIZE)); ++y)
        {
            for (int x = floor(cameraLeft / int(CHUNK_SIZE)); x <= floor(cameraRight / int(CHUNK_SIZE)); ++x)
            {
                long long key = (((long long)x) << 32) + (long long)y;
                auto it = world.find(key);
                if (it != world.end())
                {
                    if (!it->second.generated)
                        it->second.generate();
                }
                else
                {
                    world[key] = Chunk(x, y);
                    world[key].generate();
                }
                world[key].draw(mainWindow);
            }
        }

        for (int y = int(cameraTop) / int(CHUNK_SIZE) - (cameraTop < 0); y <= int(cameraBottom) / int(CHUNK_SIZE) - (cameraBottom < 0); ++y)
        {
            for (int x = int(cameraLeft) / int(CHUNK_SIZE) - (cameraLeft < 0); x <= int(cameraRight) / int(CHUNK_SIZE) - (cameraRight < 0); ++x)
            {
                long long key = coordsToKey(Vector2i(x, y));
                for (int o_i = 0; o_i < world[key].objects.size(); ++o_i)
                {
                    Object* curobj = &world[key].objects[o_i];
                    if (IntRect(curobj->position.x, curobj->position.y, objlib[curobj->contentID].collision.x, objlib[curobj->contentID].collision.y).contains(mappos))
                    {
                        o_selected = curobj;
                        RectangleShape sel(Vector2f(1, 1));
                        sel.setTexture(&selection_t);
                        //
                        sel.setPosition(Vector2f(curobj->position));
                        sel.setTextureRect(IntRect(0, 0, 32, 32));
                        mainWindow.draw(sel);
                        sel.setPosition(Vector2f(curobj->position.x, curobj->position.y + int(objlib[curobj->contentID].collision.y) - 1));
                        sel.setTextureRect(IntRect(0, 32, 32, 32));
                        mainWindow.draw(sel);
                        sel.setPosition(Vector2f(curobj->position.x + int(objlib[curobj->contentID].collision.x) - 1, curobj->position.y + int(objlib[curobj->contentID].collision.y) - 1));
                        sel.setTextureRect(IntRect(32, 32, 32, 32));
                        mainWindow.draw(sel);
                        sel.setPosition(Vector2f(curobj->position.x + int(objlib[curobj->contentID].collision.x) - 1, curobj->position.y));
                        sel.setTextureRect(IntRect(32, 0, 32, 32));
                        mainWindow.draw(sel);
                        //
                    }
                    curobj->draw(mainWindow);
                }
            }
        }

        //if (isClicked) cout << floor(pos.x) << ", " << floor(pos.y) << endl;

        mainWindow.display();
    }
    */

    return EXIT_SUCCESS;
}
