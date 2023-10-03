#include "mainmenu.h"
#include <iostream>

MainMenu::MainMenu()
{
    title = new OutText();
    title->InitText(650, 50, L"Epic Murzik run!", 150, Color(237, 147, 0), 3);
    skinButton = new Button("skinButton", 750.0f, 400.0f);
    startButton = new Button("startButton", 750.0f, 600.0f);
    currentButton = skinButton;
    startButton->SetClarity(Color(255, 255, 255, 180));
}

void MainMenu::SwitchButton()
{
    currentButton->SetClarity(Color(255, 255, 255, 180));
    if (currentButton == skinButton)
    {
        currentButton = startButton;
    }
    else if (currentButton == startButton)
    {
        currentButton = skinButton;
    }
    currentButton->SetClarity(Color(255, 255, 255, 1000));
}

std::string MainMenu::GetCurrentButtonName()
{
    return currentButton->GetName();
}

MainMenu::~MainMenu()
{
    delete skinButton;
    delete startButton;
}

void MainMenu::Draw(RenderWindow &window)
{
    title->Draw(window);
    skinButton->Draw(window);
    startButton->Draw(window);
}