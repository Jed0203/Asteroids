#include "ship.h"


// Put your ship methods here
Ship::Ship(Point point, float speed, int angle, Point topLeft
	, Point bottomRight)
{
	this->point = point;
	this->speed = speed;
	this->angle = angle;
	this->topLeft = topLeft;
	this->bottomRight = bottomRight;
}
void Ship::applyThrust()
{
	float dx = (cos((angle + 90) * M_PI / 180)) * THRUST_AMOUNT;
	float dy = (sin((angle + 90) * M_PI / 180)) * THRUST_AMOUNT;
	velocity.setDx(velocity.getDx() + dx);
	velocity.setDy(velocity.getDy() + dy);
}
void Ship::applyBrake()
{
	
}
void Ship::rotateLeft()
{
	angle -= ROTATE_AMOUNT;

}
void Ship::rotateRight()
{
	angle += ROTATE_AMOUNT;
}
void Ship::draw() const
{
	drawShip(getPoint(), angle, true);
}
