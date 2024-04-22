#ifndef __CAMERA_MANAGER__
#define __CAMERA_MANAGER__
#include "Point.h"
class CameraManager:public Point
{
public:
	CameraManager();
	void init();
	void set();
	void update();
};
#endif