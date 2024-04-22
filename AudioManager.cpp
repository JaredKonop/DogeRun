#include "AudioManager.h"
AudioManager::AudioManager()
{
	soundEngine = createIrrKlangDevice();	// Create soundengine
}
AudioManager::~AudioManager()
{
	soundEngine->drop();	// Delete soundengine
}
void AudioManager::play(const char *filename,bool loop)		// If loop==true , then the audio will play again and again
{
	soundEngine->play2D(filename,loop);		// Play an audio
}
void AudioManager::stopAll()
{
	soundEngine->stopAllSounds();	// Stop all sounds
}
