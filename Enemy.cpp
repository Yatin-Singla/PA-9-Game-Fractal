#include "Enemy.h"

Enemy::Enemy(const sf::Vector2<float> &startingPosition,
	const sf::Texture &texture, const float &speed)
{
	this->pos = startingPosition;
	this->sprite.setTexture(texture);
	this->sprite.setPosition(startingPosition);
	this->speed = speed;
	this->goUp = true;
}

Enemy::Enemy(const Enemy &enemy)
{
	this->pos = enemy.pos;
	this->sprite = enemy.sprite;
	this->speed = enemy.speed;
}

void Enemy::setPos(const sf::Vector2<float> &pos)
{
	this->pos = pos;
}

void Enemy::setSprite(const sf::Sprite &sprite)
{
	this->sprite = sprite;
}

void Enemy::setSpeed(const float & speed)
{
	if (speed > 0)
	{
		this->speed = speed;
	}
}

sf::Vector2<float> Enemy::getPos() const
{
	return this->pos;
}

sf::Sprite& Enemy::getSprite()
{
	return this->sprite;
}

float Enemy::getSpeed() const
{
	return this->speed;
}

void Enemy::incrementPosition()
{
	if (this->pos.y - speed < 0) // sprite is at the top
	{
		this->goUp = false;
	}
	else if (this->pos.y + speed > 935) // sprite is at the bottom
	{
		this->goUp = true;
	}
	this->goUp ? (this->pos.y -= speed) : (this->pos.y += speed);


	this->sprite.setPosition(pos.x, pos.y);
}
