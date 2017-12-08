#include "Arrow.h"
#include "Balloon.h"
#include "Collision.hpp"
#include "Sound.h"
#include "Menu.h"
#include "AppWrapper.h"
#include "Fractal.h"

int main()
{
	//Rendering Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu");

	Menu menu(window.getSize().x, window.getSize().y);
	sf::Texture backgroundTexture;

	if (!backgroundTexture.loadFromFile("andy.jpg"))
	{
		std::cout << "Could not load background\n";
	}

	sf::Sprite background(backgroundTexture);
	background.setScale(1.9f, 1.1f); //length, height

	//GameOver gameover(window.getSize().x, window.getSize().y);
	//sf::Texture gameoverTexture;
	//if (!gameoverTexture.loadFromFile("GameOver.jpg"))
	//{
	//	std::cout << "Could not load background\n";
	//}
	//sf::Sprite gameoverBackground(gameoverTexture);
	//gameoverBackground.setScale(1.9f, 1.1f);

	menu.PlayMusic();
	//Sound popsound("ObnoxiousScream.ogg");
	//popsound.Playback(11);
	//popsound.PlayPopSound();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						AppWrapper Game;
						Game.Run_App();
						if (!backgroundTexture.loadFromFile("GameOver.jpg"))
						{
							std::cout << "Could not load background\n";
						}
						
						break;
					case 1:
						std::cout << "Fractals button has been pressed" << std::endl;
						Fractal Mandelbrot;
						Mandelbrot.RunApp();
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(background);
		menu.draw(window);
		/*gameover.draw(window);*/
		window.display();
	}
	return 0;

}
