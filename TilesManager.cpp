#include "TilesManager.h"
#include "LevelManager.h"
#include "CameraManager.h"
#include "GameManager.h"
#include "SpikesManager.h"

extern SpikesManager spikes;
extern GameManager game;
extern CameraManager camera;
extern LevelManager level;
TilesManager::TilesManager()
{
	rows = cols = 0;
	width = 70;
	height = 70;
	tileOffsetX = tileOffsetY = 0;
	tilesField = NULL;
}

void TilesManager::draw()
{
	// Calculate Bottom-Leftmost visible tile
	offsetCols = camera.getX() / width - visibleCols / 2.0f;
	offsetRows = camera.getY() / height - visibleRows / 2.0f;

	// Clamp camera to game boundaries
	if (offsetCols < 0) offsetCols = 0;
	if (offsetRows < 0) offsetRows = 0;
	if (offsetCols > cols - visibleCols) offsetCols = cols - visibleCols;
	if (offsetRows > rows - visibleRows) offsetRows = rows - visibleRows;

	// Get offsets for smooth movement
	tileOffsetX = (offsetCols - (GLint)offsetCols) * width;
	tileOffsetY = (offsetRows - (GLint)offsetRows) * height;

	// Draw visible tile map
	for (GLint i = 0; i <= visibleRows + 1 && i + offsetRows < rows; i++)
	{
		for (GLint j = 0; j <= visibleCols + 1 && j + offsetCols < cols; j++)
		{
			if (tilesField[GLint(i + offsetRows)][GLint(j + offsetCols)].getType() == '.')
			{
				// Empty positions
			}
			else if (tilesField[GLint(i + offsetRows)][GLint(j + offsetCols)].getType() == 'o')
			{
				Texture::render(j * width - tileOffsetX, i * height - tileOffsetY, getWidth(), getHeight(), image);		// Draw coin
			}
			else
			{
				iG::iSetColor(BLACK);
				iG::iRectangle(j * width - tileOffsetX, i * height - tileOffsetY, width, height);	// Draw wall
			}
		}
	}
}

void TilesManager::init()
{
	visibleRows = iG::iGetWindowHeight() / height;
	visibleCols = iG::iGetWindowWidth() / width;
	image = Texture::load("Data\\Image\\coin.png");
}
void TilesManager::set()
{
	spikes.clear();
	rows = level.getRows();
	cols = level.getCols();

	// Allocating memory 
	tilesField = new Tile * [rows];
	for (GLint i = 0; i < rows; i++)
	{
		tilesField[i] = new Tile[cols];
	}

	// Transfering the information from levelfield to tilesfield
	for (GLint i = 0; i < rows; i++)
	{
		for (GLint j = 0; j < cols; j++)
		{
			if (level.getCell(i, j) == 'x')
			{
				spikes.addSpike(j * width, i * height);
			}
			else
			{
				tilesField[i][j].setType(level.getCell(i, j));
			}
		}
	}
}

char TilesManager::getCell(GLint row, GLint col)
{
	if (row <rows && row >-1 && col <cols && col >-1)
		return tilesField[row][col].getType();
	else
		return '#';
}

void TilesManager::setCell(GLint row, GLint col, char c)
{

	if (row <rows && row >-1 && col <cols && col >-1)
		tilesField[row][col].setType(c);
}

GLint TilesManager::getWidth()
{
	return width;
}
GLint TilesManager::getHeight()
{
	return height;
}

GLint TilesManager::getRows()
{
	return rows;
}
GLint TilesManager::getCols()
{
	return cols;
}