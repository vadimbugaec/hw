#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "platform.h"
#include "Spike.h"
#include "Food.h"
#include <vector>
using namespace sf;

class Player
{
public:
	Player();
	void jump();
	void update(float deltaTime, std::vector <Platform> &platforms);
	void Draw(RenderWindow &window);
	FloatRect getHitbox() const;
	void Death();
	bool IsDead();
	void SetPosition(float x, float y);
	void SetSkin(std::string skinname);
	Sprite* GetSprite();
	std::string GetSkinName();
	~Player();
private:
	Texture texture;
	Sprite *cat;
	std::string spriteName;
	float jumpForce;
	bool isDead;
	bool isJumping;
	bool isFalling;
	FloatRect hitbox;
	Vector2f velocity;
};