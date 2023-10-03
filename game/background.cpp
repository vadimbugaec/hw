#include "background.h"

Background::Background(const std::string& filename, float speed, bool isOffset) : speed(speed), x(0.0f)
{
    if (!texture.loadFromFile(filename))
    {
        return;
    }
    sprite.setTexture(texture);
    auto temp = sprite.getLocalBounds().width;
    if (isOffset)
    {
        x = sprite.getLocalBounds().width;
        sprite.setPosition(sprite.getLocalBounds().width, 0.0f);
    }
}


void Background::update()
{
    x -= speed;
    auto temp = sprite.getLocalBounds();
    if (x <= -sprite.getLocalBounds().width)
    {
        x = sprite.getLocalBounds().width;
    }
    sprite.setPosition(x, 0.0f);
}

void Background::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}