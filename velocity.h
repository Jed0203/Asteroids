#ifndef VELOCITY_H
#define VELOCITY_H
#include <iostream>

// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
	float dx;
	float dy;
	int angle;
	float speed;

public:
	Velocity()
	{
		dx = 0;
		dy = 0;
		angle = 0;
		speed = 0;
	}
	float getDx() const { return dx;}
	float getDy() const { return dy; }
	void setDx(float dx) { this->dx = dx;}
	void setDy(float dy) { this->dy = dy; }
	void update(int angle, float speed)
	{
		this->angle = angle;
		this->speed = speed;
	}

	
};

#endif /* velocity_h */
