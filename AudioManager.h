#include "GameManager.h"
#include <irrKlang.h>
using namespace irrklang;
class AudioManager{
	ISoundEngine *soundEngine;
public:
	AudioManager();
	~AudioManager();
	void play(const char*,bool=false);
	void stopAll();
};