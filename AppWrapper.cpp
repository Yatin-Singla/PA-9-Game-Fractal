#include "AppWrapper.h"

void AppWrapper::Run_App(void)
{
	bool firstLevelFinished = true;

srand((unsigned)time(0));
string temp = "";
bool exitCondition = false;
Balloon* enemies1stLevel[7];
Balloon* enemies2ndLevel[15];

sf::Texture redBalloonTexture, blueBalloonTexture;
redBalloonTexture.loadFromFile("balloon_red.png");
blueBalloonTexture.loadFromFile("balloon_blue.png");

sf::Texture balloonTextures[] = { redBalloonTexture, blueBalloonTexture };

// create 1st level balloons 
for (int i = 0; i < 7; ++i)
{
	enemies1stLevel[i] = new Balloon(sf::Vector2<float>((1920 - ((i + 1) * 110)), 1080 - 300),
		balloonTextures[rand() % 2], 1.0f);
	enemies1stLevel[i]->getSprite().scale(.50f, .50f);
}

// create 2nd level balloons
for (int i = 0; i < 12; ++i)
{
	enemies2ndLevel[i] = new Balloon(sf::Vector2<float>((1920 - ((i + 1) * 110)), 1080 - 300 - rand() % 750),
		balloonTextures[rand() % 2], 1.0f);
	enemies2ndLevel[i]->getSprite().scale(.50f, .50f);
}

sf::RenderWindow window(sf::VideoMode(1930, 1080), "Testing");

sf::Texture backgroundTexture, playerTexture, arrowTexture;

sf::Font font;
if (!font.loadFromFile("Cracked_Code.ttf"))
{
	cout << "Couldn't load font\n";
}
sf::Text score;
score.setFont(font);
score.setString("00000");
score.setCharacterSize(80);
score.setFillColor(sf::Color::Red);
score.setStyle(sf::Text::Bold);
score.setPosition(750, 900);
score.setOutlineColor(sf::Color::Yellow);
score.setOutlineThickness(10);


playerTexture.loadFromFile("p2_jump.png"),
backgroundTexture.loadFromFile("scrollingBackground.png"),
arrowTexture.loadFromFile("realArrow.png");

// declare variables and objects.
Player player1;
Arrow arrow(arrowTexture, 2.5f);
sf::Event event;
bool isUpPressed = false, isDownPressed = false, arrowPushed = false;

//Initialize, and adjust scaling
sf::Sprite background(backgroundTexture);
sf::Sprite player(playerTexture);
background.setScale(1.18f, 1.65f); //length, height
player.setScale(1.1f, 1.1f);

while (window.isOpen() && exitCondition == false)
{
	firstLevelFinished = true;
	for (int i = 0; i < 7; ++i)
	{
		if (enemies1stLevel[i] != nullptr)
		{
			firstLevelFinished = false;
		}
	}

	if (!firstLevelFinished) // run 1st level
	{
		for (int i = 0; i < 7; ++i)
		{
			if (enemies1stLevel[i] != nullptr)
			{
				enemies1stLevel[i]->incrementPosition();
				if (Collision::PixelPerfectTest(arrow.getSprite(), enemies1stLevel[i]->getSprite()))
				{
					temp = player1.ChangeScore();
					score.setString(temp);
					Sound popSound("collide.wav");
					popSound.PlayPopSound();
					delete enemies1stLevel[i];
					enemies1stLevel[i] = nullptr;
				}
			}
		}
	}
	else // run 2nd level
	{
		for (int i = 0; i < 12; ++i)
		{
			if (enemies2ndLevel[i] != nullptr)
			{
				enemies2ndLevel[i]->incrementPosition();
				if (Collision::PixelPerfectTest(arrow.getSprite(), enemies2ndLevel[i]->getSprite()))
				{
					temp = player1.ChangeScore();
					score.setString(temp);
					Sound popSound("collide.wav");
					popSound.PlayPopSound();
					delete enemies2ndLevel[i];
					enemies2ndLevel[i] = nullptr;

					
				}
			}
		}
	}

	if (arrow.isFlying())
	{
		arrow.incrementPosition();
	}
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::K) arrowPushed = true;
			if (event.key.code == sf::Keyboard::W) isUpPressed = true;
			if (event.key.code == sf::Keyboard::S) isDownPressed = true;
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::K) arrowPushed = false;
			if (event.key.code == sf::Keyboard::W) isUpPressed = false;
			if (event.key.code == sf::Keyboard::S) isDownPressed = false;
		}
	}
	if (arrowPushed)
	{
		arrow.setPos(player.getPosition());
		arrow.setFlying(true);
	}

	// move the player
	if (isUpPressed == true && player.getPosition().y > 0)
	{
		player.move(0, -0.8);
	}
	if (isDownPressed == true && player.getPosition().y < 880)
	{
		player.move(0, 0.8);
	}
	sf::Vector2f position = player.getPosition(); // = (15, 55)

												  // draw everything to the window
	window.draw(background);
	window.draw(player);
	window.draw(score);

	if (arrow.isFlying())
	{
		window.draw(arrow.getSprite());
	}

	if (!firstLevelFinished)
	{
		for (int i = 0; i < 7; ++i)
		{
			if (enemies1stLevel[i] != nullptr)
			{
				window.draw(enemies1stLevel[i]->getSprite());
			}
		}
	}
	else
	{
		for (int i = 0; i < 12; ++i)
		{
			if (enemies2ndLevel[i] != nullptr)
			{
				window.draw(enemies2ndLevel[i]->getSprite());
			}
		}
	}
	window.display();
	if (player1.getScore() == 1900)
	{
		exitCondition = true;
		Sleep(1700);

		player1.ExitGame();

	}
}
}

