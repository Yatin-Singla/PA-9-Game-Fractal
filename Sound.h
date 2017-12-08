#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>

using namespace std;

class Sound
{
public:
	Sound(string FileName);
	~Sound();
	void PlayPopSound(void);
	void ResetBuffer(string FileName);
private:
	sf::SoundBuffer PopSound;
	sf::Sound sound;

};