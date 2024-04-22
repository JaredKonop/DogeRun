#include "color.h"
Color::Color()
{
	r = g = b = 255;
}
Color::Color(GLfloat r, GLfloat g, GLfloat b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
void Color::setColor(GLfloat r, GLfloat g, GLfloat b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
void Color::setColor(tuple<GLfloat, GLfloat, GLfloat>rgb)
{
	this->r = get<0>(rgb);
	this->g = get<1>(rgb);
	this->b = get<2>(rgb);
}
tuple<GLfloat, GLfloat, GLfloat> Color::getColor()
{
	return make_tuple(r, g, b);
}

tuple<GLfloat, GLfloat, GLfloat> Color::random()
{
	return make_tuple(rand()%256,rand()%256,rand()%256);
}
GLint Color::getR()
{
	return r;
}
GLint Color::getG()
{
	return g;
}
GLint Color::getB()
{
	return b;
}