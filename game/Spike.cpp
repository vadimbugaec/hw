#include "Spike.h"

void Spike::Draw(RenderWindow& window)
{
	spike->setScale(0.4f, 0.4f);
	spike->setPosition(currentPosition->x,currentPosition->y);
	window.draw(*spike);
}

Spike::Spike(Image& image)
{
	texture.loadFromImage(image);
	spike = new Sprite(texture);
	currentPosition = new Vector2f();
}

Spike::~Spike()
{
	delete spike;
	delete[] currentPosition;
}

FloatRect Spike::getHitbox() const
{
	FloatRect rect = spike->getGlobalBounds();
	auto position = spike->getPosition();
	rect.top = position.y;
	rect.left = position.x;
	return rect;
}

void Spike::setPositon(float x, float y) const
{
	currentPosition->x = x;
	currentPosition->y = y;
}

void Spike::shiftPositon(float x, float y) const
{
	currentPosition->x += x;
	currentPosition->y += y;
}

bool Spike::isOnScreen() const
{
	return currentPosition->x >= -250;
}


Vector2f Spike::getPositon() const
{
	return spike->getPosition();
}

