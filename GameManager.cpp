#include "GameManager.h"
#include "LevelManager.h"
#include "TilesManager.h"
#include "CameraManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"
#include "MenuManager.h"
#include "SpikesManager.h"
#include "AudioManager.h"
#include "Texture.h"
#include "Text.h"

extern AudioManager sound;
extern SpikesManager spikes;
extern MenuManager menu;
extern ScoreManager score;
extern PlayerManager player;
extern CameraManager camera;
extern LevelManager level;
extern TilesManager tiles;
GameManager::GameManager()
{
	timer = 0;
}
void GameManager::init()
{
	// Initializaations
	level.init();
	tiles.init();
	player.init();
	camera.init();
	spikes.init();
	menu.init();
	Text::init();
	Texture::init();
}
void GameManager::set()
{
	if (level.levelUp())
	{
		// Set new level
		level.set();  
		tiles.set();
		player.set();
		camera.set();
	}
	else
	{
		sound.stopAll();
		menu.set(MenuManager::GAMEOVER);	// Player finished the game
	}
}

void GameManager::reset()
{
	timer = 0;
	level.reset();
	score.reset();
	player.reset();
}

void GameManager::incTimer()
{
	timer+=.03;		// Increase Play time
}

void GameManager::drawTime()
{
	char temp[40];
	snprintf(temp, 40, "TIME :  %.0f", timer);
	iG::iSetColor(RED);
	Text::render(iG::iGetWindowWidth() - 250.0f, iG::iGetWindowHeight() - 200.0f, temp);
}

GLfloat GameManager::getTime()
{
	return timer;
}