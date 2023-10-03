#include "OutText.h"

void OutText::InitText(float xpos, float ypos, String str, int size_font,
    Color menu_text_color, int bord, Color border_color)
{
    titul.setPosition(xpos, ypos);
    titul.setString(str);
    titul.setCharacterSize(size_font);
    titul.setFillColor(menu_text_color);
    titul.setOutlineThickness(bord);
    titul.setOutlineColor(border_color);
}

OutText::OutText()
{
    if (!font.loadFromFile("menufont.otf")) return;
    titul.setFont(font);
}

void OutText::Draw(RenderWindow& window)
{
    window.draw(titul);
}

void OutText::UpdateText(std::string str)
{
    titul.setString(str);
}

OutText::~OutText()
{
}
