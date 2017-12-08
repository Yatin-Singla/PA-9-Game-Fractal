#pragma once

#include <SFML\Graphics.hpp>

class Arrow
{
public:
	Arrow(const sf::Vector2<float> &startingPosition,
		const sf::Texture &texture, const float &speed);
	Arrow(const sf::Texture &texture, const float &speed);

	/* Setters */
	void setPos(const sf::Vector2<float> &pos);
	void setSprite(const sf::Sprite &sprite);
	void setSpeed(const float &speed);
	void setFlying(const bool &flying) { this->flying = flying; }

	/* Getters */
	sf::Vector2<float> getPos() const;
	sf::Sprite& getSprite();
	bool isFlying() const;

	void incrementPosition();

private:
	sf::Sprite sprite;
	sf::Vector2<float> pos;
	float speed;
	bool flying;
};