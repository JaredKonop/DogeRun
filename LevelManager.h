#ifndef __LEVEL_MANAGER__
#define __LEVEL_MANAGER__
#include "GameManager.h"
class LevelManager
{
	GLint levelNum,totalLevels;
	GLint cols,rows;
	
	GLint startR, startC, endR, endC;	// Starting and ending position of a level

	char** levelField;

	// Level text files
	string levels[6]=
	{
		"",
		"Data\\Levels\\Level1.txt",
		"Data\\Levels\\Level2.txt",
		"Data\\Levels\\Level3.txt",
		"Data\\Levels\\Level4.txt",
		"Data\\Levels\\Level5.txt"
	};
public:
	LevelManager();
	~LevelManager();
	void init();
	void set();	// Reading level from file
	void reset();
	void setTotalLevels(GLint);
	GLint getCols();
	GLint getRows();
	GLint getStartR();
	GLint getStartC();
	GLint getEndR();
	GLint getEndC();
	bool levelUp();
	char getCell(GLint,GLint);
	void draw();	// Draw level number at top right corner of game screen
};
#endif