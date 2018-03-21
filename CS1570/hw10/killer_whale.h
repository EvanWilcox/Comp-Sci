// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: killer_whale.h
// Desc: Header file for killer_whale.cpp

#ifndef WHALE_H
#define WHALE_H

#include "hw10.h"
#include "loc.h"

#include "sea.h"
class sea;
#include "penguin.h"
class penguin;

const short NUM_WHALE_MOVES = 3;

// Desc: The killer_whale() creates killer_whale and sets m_penguinsEaten to 0.
// Pre:  None.
// Post: A killer_whale is created.
//
// Desc: The getLoc() returns m_loc.
// Pre:  None.
// Post: m_loc is returned.
//
// Desc: The setLoc() sets m_loc.
// Pre:  None.
// Post: m_loc is set.
//
// Desc: The disLoc() finds the distance between two loc.
// Pre:  None. 
// Post: Distance is calculated and returned.
//
// Desc: The getID() returnsthe m_charID.
// Pre:  None.
// Post: m_charID is returned.
//
// Desc: The move() moves the killer_whale.
// Pre:  None.
// Post: Penguin is moved.
//
// Desc: The getPenguinsEaten() returns m_penguinsEaten.
// Pre:  None.
// Post: m_penguinsEaten is returned.


class killer_whale
{
  private:
    loc m_loc;
    int m_penguinsEaten;

    static const char m_charID;

  public:
    killer_whale():m_penguinsEaten(0){}
    loc getLoc() const{return m_loc;}
    void setLoc(const loc l);
    void setLoc(const short x, const short y);
    float distLoc(loc p1, loc p2) const;
    static char getID() {return m_charID;}
    void move(sea & s);
    short getPenguinsEaten() const{return m_penguinsEaten;}
};

#endif
