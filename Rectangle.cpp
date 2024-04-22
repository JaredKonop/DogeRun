#include "Rectangle.h"
Rectangle::Rectangle()
{
	this->width = 0;
	this->height = 0;
}
Rectangle::Rectangle(GLfloat width, GLfloat height)
{
	this->width = width;
	this->height = height;
}
void Rectangle::setWidth(GLfloat width)
{
	this->width = width;
}
void Rectangle::setHeight(GLfloat height)
{
	this->height = height;
}
GLfloat Rectangle::getHeight()
{
	return this->height;
}
GLfloat Rectangle::getWidth()
{
	return this->width;
}
void Rectangle::draw()
{
	iG::iSetColor(getColor());
	iG::iRectangle(x,y,width,height);
}
void Rectangle::setBounds(GLint x, GLint y, GLint width, GLint height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}