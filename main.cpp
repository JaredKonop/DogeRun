#include "AudioManager.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "CameraManager.h"
#include "LevelManager.h"
#include "TilesManager.h"
#include "SpikesManager.h"
#include "MenuManager.h"
#include "ScoreManager.h"
#include "color.h"

AudioManager sound;
ScoreManager score;
MenuManager menu;
SpikesManager spikes;
CameraManager camera;
PlayerManager player;
GameManager game;
LevelManager level;
TilesManager tiles;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

	glViewport(0, 0, width, height);
	iG::iSetWindowWidth(width);
	iG::iSetWindowHeight(height);
}
void update()		// Game screen update
{
	if (menu.get() == MenuManager::PLAY)
	{
		game.incTimer();
		player.update();	// Updating Player position
		spikes.update();	// Updating Spikes position
		camera.update();	// Updating camera position
	}
	Sleep(30);
}
void iG::windowSetup()
{
	// Setting bounds of pc screen
	iG::iSetScreenHeight(GetSystemMetrics(SM_CYFULLSCREEN));
	iG::iSetScreenWidth(GetSystemMetrics(SM_CXFULLSCREEN));

	// Setting position of game window
	iG::iSetWindowX(0);
	iG::iSetWindowY(0);

	// Setting game window bounds
	iG::iSetWindowHeight(iG::iGetScreenHeight());
	iG::iSetWindowWidth(iG::iGetScreenWidth());

	// Setting window background color
	iG::iSetBGColor(GREEN);
}
int main()
{
	iG::windowSetup();
	iG::iInitialize("DogeRun");
	return 0;
}

