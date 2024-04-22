#ifndef __COLOR__
#define __COLOR__
#include "GameManager.h"
#define WHITE 255,255,255
#define BLACK 0,0,0
#define BLUE 0,0,255
#define GREEN 0,255,0
#define RED 255,0,0
#define YELLOW 255,255,0
#define PURPLE 255,255,0
#define GREY 100,100,100

class Color {
protected:
	GLint r, g, b;
public:
	Color();
	Color(GLfloat r, GLfloat g, GLfloat b);
	void setColor(GLfloat r, GLfloat g, GLfloat b);
	void setColor(tuple<GLfloat, GLfloat, GLfloat>rgb);
	tuple<GLfloat, GLfloat, GLfloat> getColor();
	static tuple<GLfloat, GLfloat, GLfloat> random();
	GLint getR();
	GLint getG();
	GLint getB();
};
#endif