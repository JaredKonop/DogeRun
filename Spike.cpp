#include"Spike.h"
#include "TilesManager.h"
extern TilesManager tiles;
Spike::Spike()
{
	velX = 0;
}
void Spike::init()
{
	amplitude = 3 * tiles.getWidth();
	velX = 5;
}
void Spike::setCenter(GLfloat x,GLfloat y)
{
	setPoint(x, y);
	centerX = x;
}
void Spike::update()
{
	if (x >= centerX + amplitude)
	{
		velX = -5;
	}
	else if(x<= centerX - amplitude)
	{
		velX = 5;
	}
	x += velX;	
}

void Spike::draw()
{
}