#include "Arrow.h"

Arrow::Arrow(const sf::Vector2<float> &startingPosition,
	const sf::Texture &texture, const float &speed)
{
	this->pos = startingPosition;
	this->sprite.setTexture(texture);
	this->speed = speed;
	this->flying = false;
	this->sprite.setScale(0.35f, 0.35f);
}

Arrow::Arrow(const sf::Texture &texture, const float &speed)
{
	this->pos.x = -1;
	this->sprite.setTexture(texture);
	this->speed = speed;
	this->flying = false;
	this->sprite.setScale(0.45f, 0.45f);
}

void Arrow::setPos(const sf::Vector2<float> &pos)
{
	this->pos = pos;
}

void Arrow::setSprite(const sf::Sprite &sprite)
{
	this->sprite = sprite;
}

void Arrow::setSpeed(const float &speed)
{
	this->speed = speed;
}

sf::Vector2<float> Arrow::getPos() const
{
	return sf::Vector2<float>();
}

sf::Sprite& Arrow::getSprite()
{
	return this->sprite;
}

bool Arrow::isFlying() const
{
	return this->flying;
}

void Arrow::incrementPosition()
{
	static bool isFlying = false;

	if (this->pos.x == -1)
	{
		this->flying = true;
	}
	else if (this->pos.x + speed > 1900)
	{
		this->flying = isFlying = false;
	}
	flying == true ? (this->pos.x += speed) : (this->pos.x = -1.0f);

	this->sprite.setPosition(pos.x, pos.y);
}