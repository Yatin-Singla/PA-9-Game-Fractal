#include "Sound.h"

Sound::Sound(string FileName)
{
	if (!PopSound.loadFromFile(FileName))
	{
		cout << "Error loading the Sound" << endl;
	}
	sound.setBuffer(PopSound);
}

Sound::~Sound()
{

}

void Sound::PlayPopSound(void)
{
	cout << "Collision\n";
	sound.play();
}

void Sound::ResetBuffer(string FileName)
{
	if (!PopSound.loadFromFile(FileName))
	{
		cout << "Error loading the Sound" << endl;
	}
}