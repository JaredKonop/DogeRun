#ifndef __SPIKE__
#define __SPIKE__
#include "Rectangle.h"
#include "texture.h"
class Spike:public Rectangle
{
	GLuint image;
	GLint iWidth, iHeight;
	GLfloat velX, centerX;
	GLfloat amplitude;	// Maximum distance from center
public:
	Spike();
	void init();
	void setCenter(GLfloat,GLfloat);
	void update();		// Move spike left and right
	void draw();
};
#endif

