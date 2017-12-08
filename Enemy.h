#pragma once

#include <SFML\Graphics.hpp>

#include <iostream>

class Enemy
{
public:
	Enemy() {}
	Enemy(const sf::Vector2<float> &startingPosition,
		const sf::Texture &texture, const float &speed);
	Enemy(const Enemy &enemy);
	virtual ~Enemy() {}

	/* Setters */
	void setPos(const sf::Vector2<float> &pos);
	void setSprite(const sf::Sprite &sprite);
	void setSpeed(const float &speed);

	/* Getters */
	sf::Vector2<float> getPos() const;
	sf::Sprite& getSprite();
	float getSpeed() const;

	// Updates balloon position - should be called once per game loop iteration.
	void incrementPosition();

private:
	sf::Vector2<float> pos;
	sf::Sprite sprite;
	float speed;

	bool goUp;
};
