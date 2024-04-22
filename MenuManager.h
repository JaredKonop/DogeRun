#ifndef __MENU_MANAGER__
#define __MENU_MANAGER__
#include "GameManager.h"
#include "texture.h"
class MenuManager {
	GLuint image;
public:
	enum menus { MAIN, PLAY, SCORE, GAMEOVER };
	enum menuOption {PLAY_GAME,SCORE_BOARD,QUIT_GAME};
	MenuManager();
	void init();
	GLint get();
	void set(menus);
	void keyDown();
	void keyUp();
	void keyEnter();
	void draw();
	void drawPlayGame();
	void drawMainMenu();
	void drawGameOver();
	void drawScoreBoard();
private:
	menus menuName;
	menuOption option;
};
#endif
