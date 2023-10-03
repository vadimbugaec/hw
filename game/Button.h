#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Button
{
public:
	Button(std::string name, float x, float y);
	~Button();
	void Draw(RenderWindow& window);
	void SetClarity(Color color);
	std::string GetName();
private:
	std::string name;
	void SetButtonTexture();
	void SetButtonPosition(float x, float y);
	Sprite* button;
	Texture texture;
};