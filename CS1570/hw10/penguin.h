// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: penguin.h
// Desc: Header file for penguin.cpp


#ifndef PENG_H
#define PENG_H

#include "hw10.h"
#include <cstdlib>
#include "loc.h"

#include "sea.h"
class sea;
#include "fish.h"
class fish;
#include "killer_whale.h"
class killer_whale;

const short MAX_START_HEALTH = 80;    // penguin's highest starting health
const short MIN_START_HEALTH = 60;    // penguin's lowest starting health

const short MAX_HEALTH = 100;         // max health for penguins
const short MIN_SPAWNING_HEALTH = 70; // min health to spawn new penguin

const short FOUR_MOVE_MAX = 80;       // max health for four moves.
const short THREE_MOVE_MAX = 60;      // max health for three moves.
const short TWO_MOVE_MAX = 40;        // max health for two moves. 
const short ONE_MOVE_MAX = 20;        // max health for one move.

// Desc: The penguin() initializes a penguin to dead and assigns random health.
// Pre:  None.
// Post: A penguin is created.

// Desc: The getLoc() returns m_loc.
// Pre:  None.
// Post: m_loc is returned.
//
// Desc: The setLoc() sets m_loc given a loc or two shorts.
// Pre:  None.
// Post: m_loc is set.
//
// Desc: The disLoc() finds the distance between two loc.
// Pre:  None. 
// Post: Distance is calculated and returned.
//
// Desc: The getHealth() returns m_health.
// Pre:  None.
// Post: m_health is returned.
//
// Desc: The getID() returnsthe m_charID.
// Pre:  None.
// Post: m_charID is returned.
//
// Desc: The move() moves the penguin.
// Pre:  None.
// Post: Penguin is moved.


class penguin
{
  private:
    short m_health;
    loc m_loc;
    bool m_dead;

    static const char m_charID;

  public:
    penguin():m_dead(0){m_health = (rand() % 
      (MAX_START_HEALTH - MIN_START_HEALTH) + MIN_START_HEALTH);}
    loc getLoc() const{return m_loc;}
    void setLoc(const loc l);
    void setLoc(const short x, const short y);
    float distLoc(loc p1, loc p2) const;
    short getHealth()const {return m_health;}
    static char getID(){return m_charID;}
    void move(sea& s);
};

#endif
