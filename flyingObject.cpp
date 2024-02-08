#include "flyingObject.h"
#include "point.h"
#include "velocity.h"

FlyingObject::FlyingObject()
{
	point.setX(0);
	point.setY(0);
	velocity.setDx(0);
	velocity.setDy(0);
	alive = true;
	speed = 0;
    radius = 0;
	angle = 0;
}

FlyingObject::FlyingObject(Point point, float speed, int angle, int radius)
{
	this->point = point;
	velocity.setDx(0);
	velocity.setDy(0);
	this->speed = speed;
	this->angle = angle;
	this->radius = radius;
	alive = true;
}

void FlyingObject::draw()
{
	
}

void FlyingObject::wrapScreen()
{
	if (point.getX() < -200)
	{
		point.setX(200);
	}

	if (point.getX() > 200)
	{
		point.setX(-200);
	}

	if (point.getY() < -200)
	{
		point.setY(200);
	}

	if (point.getY() > 200)
	{
		point.setY(-200);
	}
}


// Put your FlyingObject method bodies here
