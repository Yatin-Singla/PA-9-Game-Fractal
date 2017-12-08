#include "Balloon.h"

Balloon::Balloon(const sf::Vector2<float> &pos, const sf::Texture &texture,
	const float &speed) : Enemy::Enemy(pos, texture, speed)
{

}

Balloon::~Balloon()
{

}