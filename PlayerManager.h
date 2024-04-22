#ifndef __PLAYER_MANAGER__
#define __PLAYER_MANAGER__
#include "Rectangle.h"
#include "texture.h"
class PlayerManager:public Rectangle
{
	GLuint image;

	GLfloat velX,velY;
	GLfloat newX, newY;	// Expected next position
	GLfloat gravity;

	bool onGround;	// True if player is on ground
	GLfloat row, col;
	GLint life;

	//Starting and ending position of a level
	GLint startR, startC, endR, endC;

public:
	PlayerManager();
	void update();
	void draw();
	void drawLife();	// Draw remaining lives in top right corner of game screen
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	GLfloat getRow();
	GLfloat getCol();
	void setPosition(GLfloat, GLfloat);
	void init();
	void set();
	void setStart(GLint,GLint);
	void setEnd(GLint,GLint);
	void reset();
};
#endif