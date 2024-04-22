#include "MenuManager.h"

extern MenuManager menu;
void iG::iDraw()
{
	iClear();
	switch (menu.get())
	{
	case MenuManager::PLAY:
		menu.drawPlayGame();	// Draw game screen
		break;
	case MenuManager::MAIN:
		menu.drawMainMenu();	// Draw main menu
		break;
	case MenuManager::GAMEOVER:
		menu.drawGameOver();	// Draw gameover screen
		break;
	case MenuManager::SCORE:
		menu.drawScoreBoard();		// Draw score board
		break;
	}
}