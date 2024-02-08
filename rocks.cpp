#include "rocks.h"
#include <vector>

// Put your Rock methods here


Rock::Rock(Point point, float speed, int radius, int rotationDelta, Point topLeft, Point bottomRight)
{
	this->point = point;
	this->speed = speed;
	this->radius = radius;
	this->rotationDelta = rotationDelta;
	this->topLeft = topLeft;
	this->bottomRight = bottomRight;
}

void Rock::draw()
{

}

vector <Rock*> Rock::hit()
{
	vector<Rock*> r;
	return r;
}

BigRock::BigRock(Point point)
{
	this->point = point;
	velocity.setDx(random(-2, 2));
	velocity.setDy(random(-2, 2));
}

void BigRock::draw()
{
	setAngle(getAngle() + BIG_ROCK_SPIN);
	drawLargeAsteroid(getPoint(), getAngle());
}

vector <Rock*> BigRock::hit()
{
	kill();
	vector <Rock*> newBigRocks;
	newBigRocks.push_back(new MediumRock(point, velocity.getDy() + 1, 1));
	newBigRocks.push_back(new MediumRock(point, velocity.getDy() - 1, 1));
	newBigRocks.push_back(new SmallRock(point, velocity.getDy() + 2, 1));

	return newBigRocks;
}

MediumRock::MediumRock(Point point, float speed, int angle)
{
	this->point = point;
	this->speed = speed;
	this->angle = angle;
	velocity.setDx(random(-2, 2));
	velocity.setDy(random(-2, 2));
}

void MediumRock::draw()
{
	setAngle(getAngle() + MEDIUM_ROCK_SPIN);
	drawMediumAsteroid(getPoint(), getAngle());
}

vector<Rock*> MediumRock::hit()
{
	kill();
	vector<Rock*> newMediumRocks;
	newMediumRocks.push_back(new  SmallRock(point, velocity.getDy() + 2, 1));
	newMediumRocks.push_back(new  SmallRock(point, velocity.getDy() + 2, 1));
	return newMediumRocks;
	
}

SmallRock::SmallRock(Point point, float speed, int angle)
{
	this->point = point;
	this->speed = speed;
	this->angle = angle;
	velocity.setDx(random(-2, 2));
	velocity.setDy(random(-2, 2));
}

void SmallRock::draw()
{
	setAngle(getAngle() + SMALL_ROCK_SPIN);
	drawSmallAsteroid(getPoint(), getAngle());
}

vector<Rock*> SmallRock::hit()
{
	kill();
	vector<Rock*> newSmallRocks;
	return newSmallRocks ;
}

