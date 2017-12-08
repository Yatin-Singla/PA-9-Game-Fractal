#include "Exit.h"

Exit::Exit(float width, float height)
{
	if (!font.loadFromFile("meat_buckets.ttf"))
	{
		//handle error
	}
	if (!music.openFromFile("MainMusic.ogg"))
	{
		std::cout << "Error" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setCharacterSize(70);
	menu[0].setString("Exit");
	menu[0].setPosition(sf::Vector2f(width / 2.1, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	//width/2.1
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setCharacterSize(70);
	menu[1].setString("Retry");
	menu[1].setPosition(sf::Vector2f(width / 9.1, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setCharacterSize(70);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 9.1, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Exit::~Exit()
{}

void Exit::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}


void Exit::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Exit::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Exit::PlayMusic(void)
{
	music.play();
}