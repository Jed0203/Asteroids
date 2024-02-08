#include "bullet.h"

void Bullet::fire(float angle)
{
	float dx = (cos(angle * M_PI / 180.0)) * BULLET_SPEED;
	float dy = (sin(angle * M_PI / 180.0)) * BULLET_SPEED;
	velocity.setDx(dx);
	velocity.setDy(dy);
}

// Put your bullet methods here
