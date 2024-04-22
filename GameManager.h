#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__
#include "iGraphics.h"
#include "Text.h"

class GameManager
{
	GLfloat timer;
public:
	GameManager();
	void init();
	void set();
	void reset();
	void incTimer();
	void drawTime();
	GLfloat getTime();
};
#endif