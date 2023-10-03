#include "Player.h"
#include "Platform.h"

void Player::SetPosition(float x, float y)
{
	cat->setPosition(x, y);
}

Player::Player() : isJumping(false), isFalling(false), jumpForce(1000.0f)/*, gravity(0.98f), isFalling(true), isJumpKeyPressed(false)*/
{
	SetSkin("cat.png");
}

std::string Player::GetSkinName()
{
	return spriteName;
}

void Player::SetSkin(std::string skinname)
{
	if (!texture.loadFromFile(skinname))
	{

	}
	cat = new Sprite(texture);
	cat->setScale(0.25f, 0.25f);
	cat->setPosition(0.0f, 730.0f);
	spriteName = skinname;
}

void Player::Death()
{
	isDead = true;
	if (!texture.loadFromFile("deadCat.png"))
	{

	}
	auto position = cat->getPosition();
	cat->setTexture(texture);
	cat->setScale(0.25f, 0.25f);
}

Sprite* Player::GetSprite()
{
	return cat;
}



Player::~Player()
{
	delete this->cat;
}

void Player::jump()
{
	if (!isJumping && !isFalling)
	{
		isJumping = true;
		isFalling = false;
	}
	std::cout << "y\n" << cat->getPosition().y;
	std::cout << isFalling;
	std::cout << isJumping;
}

void Player::update(float deltaTime, std::vector <Platform> &platforms)
{
	if (isDead)
	{
		cat->move(0.0f, -velocity.y * deltaTime);
		return;
	}
	if (cat->getPosition().y >= 700)
	{
		isFalling = false;
	}
	if (cat->getPosition().y <= 700 - jumpForce)
	{
		isJumping = false;
		isFalling = true;
	}
	if (isJumping)
	{
		velocity.y = -jumpForce;
		cat->move(0.0f, velocity.y * deltaTime);
	}
	if (isFalling)
	{
		velocity.y = jumpForce;
		cat->move(0.0f, velocity.y * deltaTime);
	}

	for (int i = 0; i < platforms.size(); i++)
	{
		if (getHitbox().intersects(platforms[i].getHitbox()))
		{
			if (isFalling && !(cat->getPosition().y < platforms[i].getPositon().y - 75))
			{
				break;
			}
			if (isFalling) 
			{
				isFalling = false;
				isJumping = false;
			}
			else if (isJumping)
			{
				isJumping = false;
				isFalling = true;
			}
			else if(!(!isFalling && !isJumping))
			{
				continue;
			}
			break;
		}
		else
		{
			if (!isFalling && !isJumping && cat->getPosition().y < 700)
			{
				isFalling = true;
				isJumping = false;
			}
		}
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(*cat);
}

bool Player::IsDead()
{
	return isDead;
}

sf::FloatRect Player::getHitbox() const
{
	FloatRect rect = cat->getGlobalBounds();
	auto position = cat->getPosition();
	rect.top = position.y;
	rect.left = position.x;
	return rect;
}