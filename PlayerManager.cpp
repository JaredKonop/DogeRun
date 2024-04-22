#include "PlayerManager.h"
#include "TilesManager.h"
#include "Color.h"
#include "GameManager.h"
#include "SpikesManager.h"
#include"LevelManager.h"
#include "ScoreManager.h"
#include "MenuManager.h"
#include "CameraManager.h"
#include "AudioManager.h"

extern AudioManager sound;
extern CameraManager camera;
extern PlayerManager player;
extern MenuManager menu;
extern ScoreManager score;
extern LevelManager level;
extern SpikesManager spikes;
extern GameManager game;
extern TilesManager tiles;
PlayerManager::PlayerManager()
{
	life = 3;
	velX = velY = 0;
	row = col = 0;
	newX = newY = 0;
	onGround = true;
	setColor(RED);
}
void PlayerManager::update()
{
	
	if (velX > 15.0f) velX = 10.0f;
	if (velX < -15.0f) velX = -10.0f;
	if (velY < -100.0f) velY = -100.0f;

	// Gravity
	moveDown();

	// Calculate potential new position
	newX = round(x + velX);
	newY = round(y + velY);

	// Friction
	if (onGround)
	{
		velX *= .9;
		if (fabs(velX) < .1) velX = 0;
	}
	
	// Check for Collision with wall
	if (velY < 0)	// Moving down
	{
		if (tiles.getCell(floor(newY / height), floor(x / width)) == '#' || tiles.getCell(floor(newY / height), ceil(x / width)) == '#')
		{
			newY = floor(y / height) * height;
			velY = 0;
			onGround = true;
		}
	}
			
	if (velY > 0)	// Moving up
	{
		if (tiles.getCell(ceil(newY / height), floor(x / width)) == '#' || tiles.getCell(ceil(newY / height), ceil(x / width)) == '#')
		{
			newY = ceil(y / height) * height;
			velY = -.1;
		}
	}

	if (velX > 0)	// Moving right
	{
		if (tiles.getCell(floor(newY / height), ceil(newX / width)) == '#' || tiles.getCell(ceil(newY / height), ceil(newX / width)) == '#')
		{
			newX = ceil(x / width) * width;
			velX = 0;
		}
	}
	if (velX < 0)	// Moving left
	{
		if (tiles.getCell(floor(newY / height), floor(newX / width)) == '#' || tiles.getCell(ceil(newY / height), floor(newX / width)) == '#')
		{
			newX = floor(x / width) * width;
			velX = 0;
		}
	}

	// Check for pickups
	if (tiles.getCell(floor(newY / height), floor(newX / width)) == 'o')
	{
		tiles.setCell(floor(newY / height), floor(newX / width), '.');
		score.increase();
	}

	if (tiles.getCell(floor(newY / height), ceil(newX / width)) == 'o')
	{
		tiles.setCell(floor(newY / height), ceil(newX / width), '.');
		score.increase();
	}

	if (tiles.getCell(ceil(newY / height), floor(newX / width)) == 'o')
	{
		tiles.setCell(ceil(newY / height), floor(newX / width), '.');
		score.increase();
	}

	if (tiles.getCell(ceil(newY / height), ceil(newX / width)) == 'o')
	{
		tiles.setCell(ceil(newY / height), ceil(newX / width), '.');
		score.increase();
	}

	// Apply new position
	x = newX;
	y = newY;

	// Check collision with spikes
	if (spikes.checkCollision())
	{
		set();
		life--;
	}

	// Check if game is over
	if (!life)
	{
		sound.stopAll();
		menu.set(MenuManager::GAMEOVER);
	}

	// Check if level is complete
	if (x == endC * width && y == endR * height)
	{
		game.set();
	}

}
void PlayerManager::init()
{
	this->setHeight(tiles.getHeight());
	this->setWidth(tiles.getWidth());

	image = Texture::load("Data\\Image\\player.png");
}

void PlayerManager::set()
{
	this->setStart(level.getStartR(), level.getStartC());
	this->setEnd(level.getEndR(), level.getEndC());

	newX = x = startC * height;
	newY = y = startR * width;
}
void PlayerManager::reset()
{
	life = 3;
	velX = velY = 0;
	x = y = newX = newY = 0;
	onGround = true;
}

void PlayerManager::setStart(GLint row, GLint col)
{
	startR = row;
	startC = col;
}
void PlayerManager::setEnd(GLint row, GLint col)
{
	endR = row;
	endC = col;
}
void PlayerManager::setPosition(GLfloat row, GLfloat col)
{
	newX = x = col * height;
	newY = y = row * width;
}

// Jump
void PlayerManager::moveUp()
{
	if (velY == 0 && onGround)
	{
		velY = 22.0f;
		onGround = false;
	}
}

// Gravity
void PlayerManager::moveDown()
{
	velY -= 1.0f;
}
void PlayerManager::moveRight()
{
	if (velY == 0)
	{
		velX += 5.0f;
	}
	else  // In the air
	{
		velX += 3.0f;
	}
}
void PlayerManager::moveLeft()
{
	if (velY == 0)
	{
		velX -= 5.0f;
	}		
	else  // In the air
	{
		velX -= 3.0f;
	}
}

void PlayerManager::draw()
{
	Texture::render(getX() - tiles.offsetCols * getWidth(), getY() - tiles.offsetRows * getHeight() , getWidth(), getHeight(), image);
}

void PlayerManager::drawLife()
{
	char temp[40];
	snprintf(temp, 40, "LIFE :  %d", life);
	iG::iSetColor(RED);
	Text::render(iG::iGetWindowWidth() - 250, iG::iGetWindowHeight() - 100, temp);

}
GLfloat PlayerManager::getRow()
{
	return row;
}
GLfloat PlayerManager::getCol()
{
	return col;
}