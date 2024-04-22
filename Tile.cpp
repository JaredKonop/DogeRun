#include "Tile.h"
Tile::Tile()
{
	this->type = '.';
}
void Tile::setType(char c)
{
	this->type = c;
}
char Tile::getType()
{
	return type;   
}    