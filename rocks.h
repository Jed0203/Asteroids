#ifndef rocks_h
#define rocks_h
#include <vector>

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "uiDraw.h"
using namespace std;

// classes here:
//   Rock
class Rock : public FlyingObject
{
private:
	int rotation;
	int rotationDelta;

public:
	Rock() {}
	Rock(Point point, float speed, int radius, int rotationDelta, Point topLeft, Point bottomRight);
	virtual void draw() = 0;
	virtual vector<Rock*> hit() = 0;
};
//   BigRock
class BigRock : public Rock
{

public:
	BigRock(Point point);
	vector<Rock*> hit();
	void draw();

};
//   MediumRock
	class MediumRock : public Rock
	{
	public:
		MediumRock(Point point, float speed, int angle);
		void draw();
		vector<Rock*> hit();
	};
//   SmallRock
	class SmallRock : public Rock
	{
	public:
		SmallRock(Point point, float speed, int angle);
		void draw();
		
		vector<Rock*> hit();
	};




#endif /* rocks_h */
