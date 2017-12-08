#include "Player.h"

Player::Player(int passedHealth)
{
	score = passedHealth;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int passedScore)
{
	score = passedScore;
}

Player::~Player()
{
	cout << "Inside Player destructor\n";
}

//++++++++++++++++++++Member Functions+++++++++++++++++++++++++++

string Player::ChangeScore()
{
	string scoreString = "";

	score += 100;
	scoreString = std::to_string(score);
	return scoreString;

}

void Player::ExitGame()
{

}
