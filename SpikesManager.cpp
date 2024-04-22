#include "SpikesManager.h"
#include "Spike.h"
#include "TilesManager.h"
#include "PlayerManager.h"

extern PlayerManager player;
extern TilesManager tiles;

SpikesManager::SpikesManager()
{
	
}

void SpikesManager::init()
{
	image = Texture::load("Data\\Image\\spikes.png");
}
void SpikesManager::addSpike(GLfloat x, GLfloat y)
{
	Spike temp;
	temp.init();
	temp.setCenter(x, y);
	temp.setHeight(tiles.getHeight());
	temp.setWidth(tiles.getWidth());
	s.push_back(temp);
}
void SpikesManager::update()
{
	for (int i=0;i<s.size();i++)
	{
		s[i].update();
	}
	
}
void SpikesManager::clear()
{
	s.clear();
}
bool SpikesManager::checkCollision()
{
	for (GLint i = 0;i < s.size();i++)
	{
		if (floor(player.getY() / player.getHeight()) == floor(s[i].getY() / s[i].getHeight()) || ceil(player.getY() / player.getHeight()) == floor(s[i].getY() / s[i].getHeight()))
		{
			if (s[i].getX() + s[i].getWidth() >= player.getX() && s[i].getX() + s[i].getWidth() <= player.getX() + player.getWidth())
			{
				return true;
			}
			else if (player.getX() + player.getWidth() >= s[i].getX() && player.getX() + player.getWidth() <= s[i].getX() + s[i].getWidth())
			{
				return true;
			}
		}
	}
	return false;
}
void SpikesManager::draw()
{	
	// Draw all the spikes
	for (auto i : s)
	{
		Texture::render(i.getX() - tiles.offsetCols * tiles.getWidth(), i.getY() - tiles.offsetRows * tiles.getHeight(), tiles.getWidth(), tiles.getHeight(), image);
	}	
}