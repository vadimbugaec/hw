#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
    Background(const std::string& filename, float speed, bool isOffset);
    void update();
    void Draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    float x;
};