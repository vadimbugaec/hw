#include "platform.h"
#include <iostream>

void Platform::Draw(RenderWindow& window)
{
	platform->setScale(1.0f, 1.0f);
	platform->setPosition( currentPosition->x, currentPosition->y );
	window.draw(*platform);
}

Platform::Platform(float startX, float startY, float currentX, float currentY)
{
		image.loadFromFile("platform.png");
		texture.loadFromImage(image);
		platform = new Sprite(texture);
		startPosition = new Vector2f({startX, startY});
		currentPosition = new Vector2f({currentX, currentY});
}

FloatRect Platform::getHitbox() const
{
	FloatRect rect = platform->getGlobalBounds();
	auto position = platform->getPosition();
	rect.height -= 105;
	rect.top = position.y += 75;
	rect.left = position.x;
	return rect;
}

Vector2f Platform::getPositon() const
{
	return platform->getPosition();
}

void Platform::setPositon(float x, float y) const
{
	currentPosition->x = x;
	currentPosition->y = y;
}

void Platform::shiftPositon(float x, float y) const
{
	currentPosition->x += x;
	currentPosition->y += y;
}

Platform::~Platform()
{
}
