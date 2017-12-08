#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>


#define MAX_NUMBER_OF_ITEMS 3

class Exit
{
public:
	Exit(float width, float height);
	~Exit();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void PlayMusic(void);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Music music;

};