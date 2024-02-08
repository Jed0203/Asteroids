/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "rocks.h"
#include "ship.h"
#include "point.h"
#include <vector>

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

Game::Game(Point t1, Point br) : topLeft(t1), bottomRight(br)
{
    
    createInitialAsteriods();
    createShip();
  
    

}

Game::~Game()
{
    if (asteroids.size() != NULL)
        asteroids.clear();
}

void Game::advance()
{
    ship->advance();
    advanceRocks();
    advanceBullet();
    handleCollision();
}

void Game::advanceRocks()
{
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i]->isAlive())
        {
            asteroids[i]->advance();

        }
    }

   
}

void Game::advanceBullet()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isAlive())
        {
            // this bullet is alive, so tell it to move forward
            bullets[i]->advance();

        }

        bullets[i]->setLives(bullets[i]->getLives() - 1);
        if (bullets[i]->getLives() <= 0)
        {
            bullets[i]->kill();
        }

    }
}



void Game::handleInput(const Interface& ui)
{
    // Change the direction of the ship
    if (ui.isUp())
    {
        ship->applyThrust();
    }

    if (ui.isRight())
    {
        ship->rotateLeft();
    }

    if (ui.isLeft())
    {
        ship->rotateRight();
    }

    if (ui.isDown())
    {
        ship->applyBrake();
    }

    // Check for "Spacebar
    if (ui.isSpace())
    {
        Bullet* newBullet;
        newBullet = new Bullet(ship->getPoint());
        newBullet->fire(ship->getAngle() + 90);

        bullets.push_back(newBullet);
    }
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosetDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);

}


void Game::createInitialAsteriods()
{
    for (int i = 0; i < 5; i++)
    {
        Point point(random(-200, 200), random(-200, 200));
        asteroids.push_back(new BigRock(point));
    }

}

void Game::createShip()
{
    Point point(random(-200, 200), random(-200, 200));
    ship = new Ship(point, 0, 0, topLeft, bottomRight);

}


void Game::handleCollision()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        for (int m = 0; m < asteroids.size(); m++)
        {
            if (bullets[i]->isAlive())
            {

                if (asteroids[m] != NULL && asteroids[m]->isAlive())
                {


                    if (getClosetDistance(*bullets[i], *asteroids[m]) < 16)
                    {
                        vector <Rock*> newRocks;                   
                        newRocks = asteroids[m]->hit();
                        asteroids.insert(asteroids.end(), newRocks.begin(), newRocks.end());
                       
                        bullets[i]->kill();
                        break;
                    }

                    if (getClosetDistance(*bullets[i], *asteroids[m]) < 8)
                    {
                        vector <Rock*> newMrocks;
                        newMrocks = asteroids[m]->hit();
                        asteroids.insert(asteroids.end(), newMrocks.begin(), newMrocks.end());

                        bullets[i]->kill();
                        break;
                    }

                    if (getClosetDistance(*bullets[i], *asteroids[m]) < 4)
                    {
                        vector <Rock*> newSrocks;
                        newSrocks = asteroids[m]->hit();

                        bullets[i]->kill();
                        break;
                    }
                }
            }
        }
    }
}


void Game::cleanupZombies()
{
    
    if (asteroids.size() != NULL)
    {
        asteroids.clear();
    }

    vector<Bullet*>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        Bullet* bullet = *bulletIt;
        if (!bullet->isAlive())
        {
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++;
        }
    }
}



void Game::draw(const Interface& ui)
{
    for (int i = 0; i < asteroids.size(); i++) 
    {
        if (asteroids[i] != NULL && asteroids[i]->isAlive()) 
        {
            asteroids[i]->draw();
        }
    }

    if (ship->isAlive())
    {
        ship->draw();
    }

    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isAlive())
        {
            bullets[i]->draw();
        }
    }
}
