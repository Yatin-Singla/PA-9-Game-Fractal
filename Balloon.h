#pragma once

#include "Enemy.h"

class Balloon : public Enemy, public sf::CircleShape
{
public:
	Balloon(const sf::Vector2<float> &pos, const sf::Texture &texture,
		const float &speed);
	~Balloon();

private:

};