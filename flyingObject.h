#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"



// Put your FlyingObject class here
class FlyingObject
{
protected:
	Point point;
	Point topLeft;
	Point bottomRight;
	Velocity velocity;
	bool alive;
	float speed;
	int radius;
	int angle;
	

public:
	FlyingObject();
	FlyingObject(Point point, float speed, int angle, int radius);
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return velocity; }
	int getAngle()const { return angle; }
	bool isAlive() const { return alive; }
	void setPoint(Point point) { this->point = point; }
	void setVelocity(Velocity velcoity) { this->velocity = velocity; }
	void setAlive(bool alive) { this->alive = alive; }
	void setAngle(int angle) { this->angle= angle; }
	void kill() { this->alive = false; }
	void advance() {
		point.addX(velocity.getDx());
		point.addY(velocity.getDy());
		wrapScreen();
	}
	virtual void draw();
	void wrapScreen();

};

#endif /* flyingObject_h */
