#ifndef __SCORE_MANAGER__
#define __SCORE_MANAGER__
#include "GameManager.h"
class ScoreManager {
	GLint currentScore,totalR;
	string name;	// Name of player
	GLint selectedR;	// Score board's selected row
public:
	ScoreManager();
	void increase();	// Increasing the score after every pickup
	void draw();	// Draw score at top right corner of game screen
	void drawBoard();	// Draw score board
	void drawGameOver();	// Draw score at gameover screen
	void reset();
	void save();
	void edit();
	void erase();
	void nameEntry(int);	// Add every key that is pressed at gameover screen to player's name
	void keyDown();
	void keyUp();
};
#endif
