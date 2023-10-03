#include "Button.h"

Button::Button(std::string buttonname, float x, float y)
{
	name = buttonname;
	SetButtonTexture();
	SetButtonPosition(x, y);
}

void Button::SetClarity(Color color)
{
	button->setColor(color);
}


void Button::SetButtonPosition(float x, float y)
{
	button->setPosition(x, y);
}

std::string Button::GetName()
{
	return name;
}

void Button::SetButtonTexture()
{
	if (!texture.loadFromFile(name + ".png"))
	{
		return;
	}
	button = new Sprite(texture);
	button->setScale(1.0f, 1.0f);
}

Button::~Button()
{
	delete button;
}

void Button::Draw(RenderWindow& window)
{
	window.draw(*button);
}