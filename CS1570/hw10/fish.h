// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: fish.h
// Desc: Header file for fish.h

#ifndef FISH_H
#define FISH_H
#include "sea.h"
#include "loc.h"
class sea;

const short MAX_NUM_FOOD = 10;      // max food value
const short MIN_NUM_FOOD = 1;       // min food value

const short MOVEABLE_TILES = 8;     // number of tiles a fish can move to

const short MAX_NUM_TRIES = 20;     // tmax tries a fish has to move

// Desc: The fish() will construct a fish.
// Pre:  None.
// Post: A fish is constructed.
//
// Desc: The getLoc() returns m_loc.
// Pre:  None.
// Post: m_loc is returned.
//
// Desc: The setLoc() will set m_loc to a given location.
// Pre:  None.
// None: m_loc is set.
//
// Desc: The move() will move the fish.
// Pre:  None.
// Post: The fish is moved.
//
// Desc: The getID() returns m_charID. 
// Pre:  None.
// Post: m_charID is returned.
//
// Desc: The getFood() returns m_food.
// Pre:  None.
// Post: m_food is returned.


class fish
{
  private: 
    short m_food;
    loc m_loc;
    bool m_dead;

    static const char m_charID;

  public:
    fish():m_dead(0){m_food = MIN_NUM_FOOD + (rand() % MAX_NUM_FOOD);}

    loc getLoc() const{return m_loc;}
    void setLoc(const loc l);

    void move(const sea& s);
    
    static char getID() {return m_charID;}
    short getFood() const{return m_food;}
    };

#endif
