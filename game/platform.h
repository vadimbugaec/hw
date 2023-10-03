#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Platform
{
public:
	Platform(float startX, float startY, float currentX, float currentY);
	~Platform();
	void Draw(RenderWindow& window);
	sf::FloatRect getHitbox() const; 
	Vector2f getPositon() const;	
	void setPositon(float x, float y) const;
	void shiftPositon(float x, float y) const;
	float RespawnDelay;
private:
	Image image;
	Sprite *platform;
	Texture texture;
	Vector2f *startPosition;
	Vector2f *currentPosition;
	sf::FloatRect platformHitbox;
};