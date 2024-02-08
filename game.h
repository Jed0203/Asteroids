/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/
#ifndef GAME_H
#define GAME_H
#include <vector>

#include "point.h"
#include "uiInteract.h"
#include "bullet.h"
#include "rocks.h"
#include "ship.h"
#include "uiDraw.h"
#define CLOSE_ENOUGH 15

using namespace std;
/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
private:
    Point topLeft;
    Point bottomRight;
    vector<Bullet *> bullets;
    vector<Rock *> asteroids;
    Ship* ship;

    

public:
    /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
    Game(Point topLeft, Point topRight);
    ~Game();

    /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
    void handleInput(const Interface & ui);

    /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
    void advance();
    void advanceRocks();
    void advanceBullet();
    /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
    void draw(const Interface & ui);
    void createInitialAsteriods();
    void createShip();
    void handleCollision();
    /*********************************************
    * Function: cleanupZombies
    * Description: clean the useless memory
    *********************************************/
    void cleanupZombies();
    float getClosetDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;



};




#endif /* GAME_H */
