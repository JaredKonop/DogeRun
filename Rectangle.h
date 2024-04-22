#ifndef __RECTANGLE__
#define __RECTANGLE__
#include "Object.h"
#include "GameManager.h"
class Rectangle: public Object {
protected:
	GLfloat height, width;
public:
	Rectangle();
	Rectangle(GLfloat width, GLfloat height);
	void setWidth(GLfloat width);
	void setHeight(GLfloat height);
	GLfloat getHeight();
	GLfloat getWidth();
	void draw();
	void setBounds(GLint x, GLint y, GLint width, GLint height);
};
#endif