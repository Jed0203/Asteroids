#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
#include "flyingObject.h"
#include "uiDraw.h"
#include "ship.h"
#include <cmath>



// Put your Bullet class here
class Bullet : public FlyingObject
{
private:
	int lives;

public:
	Bullet() : FlyingObject() {  }
	int getLives() const { return lives; }
	void setLives(int l) { this->lives = l; }
	Bullet(const Point& point) { this->point = point; setLives(BULLET_LIFE); }
	void fire(float angle);
	void draw() { drawDot(getPoint()); }
};



#endif /* bullet_h */
