#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "OutText.h"
using namespace sf;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void Draw(RenderWindow &window);
	void SwitchButton();
	std::string GetCurrentButtonName();
private:
	Button *startButton;
	Button *skinButton;
	Button *currentButton;
	OutText *title;
};