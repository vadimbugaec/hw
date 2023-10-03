#include "Food.h"

void Food::Draw(RenderWindow& window)
{
	food->setScale(0.45f, 0.45f);
	food->setPosition(currentPosition->x, currentPosition->y);
	window.draw(*food);
}

Food::Food(Image& image)
{
	texture.loadFromImage(image);
	food = new Sprite(texture);
	currentPosition = new Vector2f();
}

Food::~Food()
{
	delete food;
	delete[] currentPosition;
}

FloatRect Food::getHitbox() const
{
	FloatRect rect = food->getGlobalBounds();
	auto position = food->getPosition();
	rect.top = position.y;
	rect.left = position.x;
	return rect;
}

void Food::setPositon(float x, float y) const
{
	currentPosition->x = x;
	currentPosition->y = y;
}

void Food::shiftPositon(float x, float y) const
{
	currentPosition->x += x;
	currentPosition->y += y;
}

bool Food::isOnScreen() const
{
	return currentPosition->x >= -250;
}

Vector2f Food::getPositon() const
{
	return food->getPosition();
}