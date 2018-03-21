// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: sea.h
// Desc: Header file for sea.cpp

#ifndef SEA_H
#define SEA_H

#include "penguin.h"
#include "killer_whale.h"
#include "fish.h"
class penguin;
class killer_whale;
class fish;

#include <iostream>
#include <cstdlib>

const short MAX_SIZE = 25;            // max size of the sea

const char EMPTY = '^';               // character for the empty cells

const short MAX_WHALES = 2;           // max number of whales in the sim
const short MAX_PENGUINS = 50;        // max number of penguins in the sim
const short MAX_FISHES = 200;         // max number of fish in the sim

const short START_NUM_FISH = 35;      // starting number of fish in the sim
const short START_NUM_PENGUINS = 20;  // starting number of penguins in the sim


// Desc: The sea() creates a sea with size set to given parameter ot default.
// Pre:  None.
// Post: A sea is created.
//
// Desc: The setPos() sets the value in m_theSea of a given location.
// Pre:  None.
// Post: A value is set in m_theSea.
//
// Desc: The clearPos() clears the value in m_theSea of a given location.
// Pre:  None.
// Post: The value of a given location is cleared.
//
// Desc: The isFull() checks to see if a location in m_theSea is full.
// Pre:  None.
// Post: Returns true if cell is full, false if not.
//
// Desc: The getSize() returns m_size.
// Pre:  None.
// Post: m_size is returned.
//
// Desc: The clear() clears sets the value of m_theSea to EMPTY.
// Pre:  None.
// Post: m_theSea is cleared.
//
// Desc: The update() updates the visual of the sea.
// Pre:  None.
// Post: m_theSea is updated.
//
// Desc: The populate() adds the initial characters to the sea.
// Pre:  None.
// Post: Characters are added.
//
// Desc: The move() adds fish to sea and moves all characters in sea.
// Pre:  m_spawnRate must be set with setSpawnRate().
// Post: All characters are moved.
//
// Desc: The getPositon() returns the character in the location given.
// Pre:  None.
// Post: A character is returned.
//
// Desc: The newPenguin() adds new penguin to m_penguins.
// Pre:  None.
// Post: New penguin is added to m_penguins.
//
// Desc: The operator<<() overloads the insertion operator.
// Pre:  None.
// Post: The insertion operator is overloaded.
//
// Desc: The addFish() adds a given fish to m_fishes.
// Pre:  None.
// Post: Given fish is added to m_fishes.
//
// Desc: The killFish() decreases m_numFishAlive.
// Pre:  m_numFishAlive > 0.
// Post: m_numFishAlive is decreased by 1.
//
// Desc: The killPenguin() decreases m_numPenguinAlive
// Pre:  m_numPenguinAlive > 0.
// Post: m_numPenguinAlive is decreased by 1.
//
// Desc: The distLoc() finds the distance between two loc.
// Pre:  None.
// Post: Distance is returned.
//
// Desc: The getNumFish() returns m_numFishAlive.
// Pre:  None.
// Post: m_numFishAlive is returned.
//
// Desc: The getNumPenguins() returns m_numPenguinAlive.
// Pre:  None.
// Post: m_numPenguinAlive is returned.
//
// Desc: The getNumWhales() returns m_numWhaleAlive
// Pre:  None.
// Post: m_numWhaleAlive is returned.
//
// Desc: The getFish() returns m_fishes[i].
// Pre:  m_fishes[i] must be data.
// Post: m_fishes[i] is returned.
//
// Desc: The getPenguin() returns m_penguins[i].
// Pre:  m_penguins[i] must be data.
// Post: m_penguins[i] is returned.
//
// Desc: The getWhale() returns m_whale[i].
// Pre:  m_kWhales[i] must be data.
// Post: m_kWhales[i] is returned.
//
// Desc: The setFish() sets m_fishes[i] to f.
// Pre:  m_fishes[i] must be data.
// Post: m_fishes[i] is set to f.
//
// Desc: The setPenguin() sets m_penguins[i] to p.
// Pre:  m_penguins[i] must be data.
// Post: m_penguins[i] is set to p.
//
// Desc: The setSpawnRate() sets m_numNewFish.
// Pre:  None.
// Post: m_numNewFish is set to spawnRate.
//

class sea
{
  private: 
    char m_theSea[MAX_SIZE][MAX_SIZE];
    short m_size;

    killer_whale* m_kWhales;
    penguin* m_penguins;
    fish* m_fishes;

    short m_numFishAlive;
    short m_numPenguinAlive;
    short m_numWhaleAlive;

    short m_numNewFish;

  public:
    sea();
    sea(const short s);

    template <typename T>
      void setPos(const T& t);

    template <typename T>
      void clearPos(const T& t);

    bool isFull(const loc l) const;
    short getSize() const{return m_size;}

    void clear();
    void update();
    void populate();
    void move();

    char getPosition(const int x, const int y) const;
    void newPenguin();
    friend ostream& operator <<(ostream& os, const sea& s);
    
    void addFish(const fish f);
    void killFish();
    void killPenguin();

    float distLoc(loc p1, loc p2);

    short getNumFish() const{return m_numFishAlive;}
    short getNumPenguins() const{return m_numPenguinAlive;}
    short getNumWhales() const{return m_numWhaleAlive;}
    
    fish getFish(const short i) const;
    penguin getPenguin(const short i) const;
    killer_whale getWhale(const short i) const;
    
    void setFish(const short i, const fish f);
    void setPenguin(const short i, const penguin p);
    void setSpawnRate(const short spawnRate);

};

  template <typename T>
void sea::setPos(const T& t)
{
  m_theSea[t.getLoc().m_x][t.getLoc().m_y] = t.getID();
  return;
}

  template <typename T>
void sea::clearPos(const T& t)
{
  m_theSea[t.getLoc().m_x][t.getLoc().m_y] = EMPTY;
  return;
}


#endif
