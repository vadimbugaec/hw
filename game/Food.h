#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Food
{
public:
	Food(Image& image);
	~Food();
	void Draw(RenderWindow& window);
	sf::FloatRect getHitbox() const;
	Vector2f getPositon() const;
	void setPositon(float x, float y) const;
	void shiftPositon(float x, float y) const;
	bool isOnScreen() const;
private:
	Sprite* food;
	Texture texture;
	Vector2f* startPosition;
	Vector2f* currentPosition;
	sf::FloatRect spikeHitbox;
};