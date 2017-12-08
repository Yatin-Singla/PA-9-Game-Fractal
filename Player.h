#include <iostream>
#include <Windows.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using std::cout;
using std::string;

class Player
{
public:
	Player(int Score = 0);
	~Player();

	string ChangeScore();
	void ExitGame();

	int getScore();
	void setScore(int passedHealth);

private:
	int score;
};

