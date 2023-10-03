#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "mainmenu.h"
#include "Player.h"
#include "platform.h"
#include "background.h"
#include "Food.h"
#include "Spike.h"
#include "OutText.h"
#include "Wardrobe.h"
#include <stdlib.h>
#include <time.h>
using namespace sf;

enum GameState
{
    IsStartMenu,
    IsSelectingSkin,
    GameIsStarted
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Epic Murzik run!");
    window.setFramerateLimit(165);

    sf::Music music;

    if (!music.openFromFile("catplatformer.wav")) 
    {

    }

    srand(time(NULL));

    //INIT
    MainMenu mainmenu;
    OutText deathText;
    OutText foodCounter;
    int foodCount = 0;
    foodCounter.InitText(30, 0, "foodcount: " + std::to_string(foodCount), 60, Color(226, 57, 16), 3);
    deathText.InitText(650, 400, L"Youre dead!", 150, Color(226, 57, 16), 3);

    Player player;
    std::vector <std::string> skinsFileName;
    skinsFileName.push_back("cat.png");
    skinsFileName.push_back("cat2.png");
    int skinNumber = 0;

    Wardrobe wardrobe;

    std::vector <float> coord;
    coord.push_back(500);
    coord.push_back(300);
    coord.push_back(100);

    std::vector <float> platfromDelay;
    platfromDelay.push_back(0.2);
    platfromDelay.push_back(0.4);
    platfromDelay.push_back(0.8);

    std::vector <Platform> platforms;
    Platform *platform1 = new Platform(400.0f, 500.0f, 000.0f, 200.0f);
    Platform *platform2 = new Platform(700.0f, 500.0f, 700.0f, 500.0f);
    Platform *platform3 = new Platform(1000.0f, 500.0f, 1500.0f, 300.0f);
    platforms.push_back(*platform1);
    platforms.push_back(*platform2);
    platforms.push_back(*platform3);
    
    std::vector <Spike> spikes;
    Image imageSpike;
    imageSpike.loadFromFile("spike.png");
    Spike *spike1 = new Spike(imageSpike);
    spike1->setPositon(-500.0f, 0.0f);
    
    std::vector <Food> foods;
    Image imageFood;
    imageFood.loadFromFile("food.png");
    Food *food1 = new Food(imageFood);
    food1->setPositon(-500.0f, 0.0f);
    
    spikes.push_back(*spike1);
    foods.push_back(*food1);

    Background background1("back.png", 0.35f, false);
    Background background2("back.png", 0.35f, true);

    music.setLoop(true);
    music.play();

    int gamestate = IsStartMenu;
    while (window.isOpen())
    {
        if (gamestate == IsStartMenu)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    return 0;
                }
                if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Up || event.key.code == Keyboard::Down))
                {
                    mainmenu.SwitchButton();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    std::string buttonName = mainmenu.GetCurrentButtonName();
                    if (buttonName == "skinButton")
                    {
                        gamestate = IsSelectingSkin;
                    }
                    else if (buttonName == "startButton")
                    {
                        gamestate = GameIsStarted;
                    }
                }
            }
            window.clear();
            background1.Draw(window);
            mainmenu.Draw(window);
            window.display();
        }

        else if (gamestate == IsSelectingSkin)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && (event.key.code == Keyboard::Right || event.key.code == Keyboard::Left))
                {
                    wardrobe.ChangeSkin();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {

                    gamestate = GameIsStarted;
                    player.SetSkin(wardrobe.GetSelectedSkin());
                }
            }
            window.clear();
            background1.Draw(window);
            wardrobe.Draw(window);
            window.display();
        }
        else
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    player.jump();
                }
            }
            float deltaTime = 0.00606;
            player.update(deltaTime, platforms);
            window.clear();
            background1.update();
            background2.update();
            background1.Draw(window);
            background2.Draw(window);
            foodCounter.UpdateText("Foodcount: " + std::to_string(foodCount));
            foodCounter.Draw(window);
            if (player.IsDead())
            {
                deathText.Draw(window);
                player.Draw(window);
                window.display();
                continue;
            }

            for (int i = 0; i < platforms.size(); i++)
            {
                platforms[i].Draw(window);
                platforms[i].shiftPositon(-3.5, 0.0);
                if (platforms[i].getPositon().x <= -500)
                {
                    if (platforms[i].RespawnDelay > 0.0f)
                    {
                        platforms[i].RespawnDelay -= deltaTime;
                        continue;
                    }
                    platforms[i].setPositon(1800.0f, coord[rand() % coord.size()]);
                    int random3 = rand() % 3;
                    platforms[i].RespawnDelay = platfromDelay[random3];
                    if (random3 == 0)
                    {
                        for (int j = 0; j < foods.size(); j++)
                        {
                            if (!foods[j].isOnScreen())
                            {
                                int random2 = rand() % 2;
                                if (random2 == 0)
                                {
                                    foods[j].setPositon(800.0f, 700.0f);
                                }
                                else
                                {
                                    auto platformPosition = platforms[i].getPositon();
                                    foods[j].setPositon(platformPosition.x, platformPosition.y);
                                }
                                foods[j].Draw(window);
                                break;
                            }
                        }
                    }
                    else if (random3 == 1)
                    {
                        for (int j = 0; j < spikes.size(); j++)
                        {
                            if (!spikes[j].isOnScreen())
                            {
                                int random2 = rand() % 2;
                                if (random2 == 0)
                                {
                                    spikes[j].setPositon(800.0f, 826.0f);
                                }
                                else
                                {
                                    auto platformPosition = platforms[i].getPositon();
                                    spikes[j].setPositon(platformPosition.x, platformPosition.y);
                                }
                                spikes[j].Draw(window);
                                break;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < foods.size(); i++)
            {
                if (foods[i].isOnScreen())
                {
                    if (player.getHitbox().intersects(foods[i].getHitbox()))
                    {
                        foods[i].setPositon(-500.0f, -500.0f);
                        foodCount++;
                    }
                    foods[i].shiftPositon(-3.5f, 0.0f);
                    foods[i].Draw(window);
                }

            }
            for (int i = 0; i < spikes.size(); i++)
            {
                if (spikes[i].isOnScreen())
                {
                    if (player.getHitbox().intersects(spikes[i].getHitbox()))
                    {
                        player.Death();
                    }
                    spikes[i].shiftPositon(-3.5f, 0.0f);
                    spikes[i].Draw(window);
                }
            }
            player.Draw(window);
            window.display();
        }
    }
    music.stop();
    return 0;
}