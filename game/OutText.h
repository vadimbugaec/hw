#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class OutText
{
public:
	OutText();
	~OutText();
	void InitText(float xpos, float ypos, String str, int size_font = 60,
		Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);
	void Draw(RenderWindow& window);
	void UpdateText(std::string str);
private:
	Text titul;
	Font font;
};