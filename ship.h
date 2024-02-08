#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define M_PI 3.141592653589793
#include "flyingObject.h"
#include "uiDraw.h"
#include <cmath>


// Put your Ship class here
class Ship : public FlyingObject
{
public:
	Ship() {  }
	Ship(Point point, float speed, int angle, Point topLeft
		, Point bottom);
	void applyThrust();
	void applyBrake();
	void rotateLeft();
	void rotateRight();
	void draw()const;

};

#endif /* ship_h */
