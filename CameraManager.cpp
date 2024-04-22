#include "CameraManager.h"
#include "PlayerManager.h"

extern PlayerManager player;
CameraManager::CameraManager()
{

}
void CameraManager::set()
{
	// Link camera to player position
	setPoint(player.getX(), player.getY());
}
void CameraManager::init()
{
	
}
void CameraManager::update()
{
	setPoint(player.getX(), player.getY());	// Update camera position with player
}
