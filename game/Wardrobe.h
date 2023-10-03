#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
using namespace sf;

class Wardrobe
{
public:
	Wardrobe();
	~Wardrobe();
	void Draw(RenderWindow &window);
	void ChangeSkin();
	void SetClarity(Color color);
	std::string GetSelectedSkin();
private:
	std::vector <Player> skins;
	int selectedSkinId;
};

