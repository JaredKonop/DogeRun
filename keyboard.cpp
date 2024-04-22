#include "GameManager.h"
#include "PlayerManager.h"
#include "MenuManager.h"
#include "ScoreManager.h"
#include "AudioManager.h"

extern AudioManager sound;
extern ScoreManager score;
extern MenuManager menu;
extern PlayerManager player;

void iG::iKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (menu.get())
	{
	case MenuManager::MAIN:
		if (action == GLFW_PRESS)
		{
			switch (key)
			{
			case GLFW_KEY_UP:
				menu.keyUp();
				break;
			case GLFW_KEY_DOWN:
				menu.keyDown();
				break;
			case GLFW_KEY_Q:
				exit(0);
				break;
			case GLFW_KEY_ENTER:
				menu.keyEnter();
				break;
			}
		}
		break;

	case MenuManager::PLAY:
		switch (key)
		{
		case GLFW_KEY_UP:
			player.moveUp();
			break;
		case GLFW_KEY_DOWN:
			player.moveDown();
			break;
		case GLFW_KEY_LEFT:
			player.moveLeft();
			break;
		case GLFW_KEY_RIGHT:
			player.moveRight();
			break;
		case GLFW_KEY_END:
			menu.set(MenuManager::MAIN);
			break;
		case GLFW_KEY_BACKSPACE:
			sound.stopAll();
			menu.set(MenuManager::MAIN);
			break;

		}
		break;
	case MenuManager::SCORE:
		if (action == GLFW_PRESS)
		{
			switch (key)
			{
			case GLFW_KEY_UP:
				score.keyUp();
				break;
			case GLFW_KEY_DOWN:
				score.keyDown();
				break;
			case GLFW_KEY_BACKSPACE:
				menu.set(MenuManager::MAIN);
				break;
			case GLFW_KEY_D:
				score.erase();
				break;
			case GLFW_KEY_E:
				score.edit();
				break;
			}
			break;
		}

	case MenuManager::GAMEOVER:
		if (action == GLFW_PRESS)
		{
			score.nameEntry(key);
		}
		break;
	}
}
