#include "Wardrobe.h"

Wardrobe::Wardrobe()
{
	skins.push_back(*(new Player()));
	skins.push_back(*(new Player()));
	skins[0].SetSkin("cat.png");
	skins[1].SetSkin("cat2.png");
	selectedSkinId = 0;
	SetClarity(Color(255, 255, 255, 500));
}

void Wardrobe::ChangeSkin()
{
	SetClarity(Color(255, 255, 255, 180));
	selectedSkinId = (++selectedSkinId) % skins.size();
	SetClarity(Color(255, 255, 255));
}

void Wardrobe::SetClarity(Color color)
{
	Sprite *catSprite = (skins[selectedSkinId].GetSprite());
	catSprite->setColor(color);
}

std::string Wardrobe::GetSelectedSkin()
{
	return (skins[selectedSkinId]).GetSkinName();
}

void Wardrobe::Draw(RenderWindow &window)
{
	for (int i = 0; i < skins.size(); i++)
	{
		skins[i].GetSprite()->setScale(0.5f, 0.5f);
		skins[i].SetPosition(400.0f + 750.0f * i, 400.0f);
		skins[i].Draw(window);
	}
}

Wardrobe::~Wardrobe()
{
}