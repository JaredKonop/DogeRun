#ifndef __TILE__
#define __TILE__
#include "GameManager.h"
#include "Rectangle.h"
class Tile:public Rectangle {
	char type;
public:
	Tile();
	void setType(char);
	char getType();
};
#endif