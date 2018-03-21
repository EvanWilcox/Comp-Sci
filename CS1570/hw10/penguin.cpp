// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: penguin.cpp
// Desc: Implemetation for penguin.h

#include "penguin.h"
#include <cmath>

void penguin::setLoc(const loc l)
{
  m_loc.set(l.m_x, l.m_y);
  return;
}

void penguin::setLoc(const short x, const short y)
{
  m_loc.set(x, y);
  return;
}

float penguin::distLoc(loc p1, loc p2) const
{
  return sqrt((p2.m_x - p1.m_x)*(p2.m_x - p1.m_x) 
      + (p2.m_y - p1.m_y)*(p2.m_y - p1.m_y));
}

void penguin::move(sea& s)
{
  // sets closest to irrevelant location
  loc closestFish(s.getSize(), s.getSize());
  bool foundFish = false;
  // find closest fish to penguin
  for (int j = 0; j < s.getSize(); j++)
  {
    for (int k = 0; k < s.getSize(); k++)
    {
      loc newLoc(j, k);
      if (distLoc(getLoc(), newLoc) < distLoc(getLoc(), closestFish) 
          && s.getPosition(j, k) == fish::getID())
      {
        foundFish = true;
        closestFish = newLoc;
      }
    }
  }
  // sets closest to irrevelant location
  loc closestWhale(s.getSize(), s.getSize());
  // find closest whale to penguin
  for (int j = 0; j < s.getSize(); j++)
  {
    for (int k = 0; k < s.getSize(); k++)
    {
      loc newLoc(j, k);
      if (distLoc(getLoc(), newLoc) < distLoc(getLoc(), closestFish) 
          && s.getPosition(j, k) == killer_whale::getID())
      {
        closestWhale = newLoc;
      }
    }
  }

  // determine number of moves
  short numMoves;
  if (getHealth() < MAX_HEALTH && getHealth() > FOUR_MOVE_MAX)
    numMoves = 5;
  else if (getHealth() <= FOUR_MOVE_MAX && getHealth() > THREE_MOVE_MAX)
    numMoves = 4;
  else if (getHealth() <= THREE_MOVE_MAX && getHealth() > TWO_MOVE_MAX)
    numMoves = 3;
  else if (getHealth() <= TWO_MOVE_MAX && getHealth() > ONE_MOVE_MAX)
    numMoves = 2;
  else
    numMoves = 1;

  short counter = 0;
  bool hasEaten = false;
  bool moveRandom = false;
  if (closestFish == loc(s.getSize(), s.getSize()))
    moveRandom = true;

  // move towards fish
  do
  {
    if (foundFish)
    {
      if (!moveRandom)
      {
        if (getLoc().m_x < closestFish.m_x 
            && s.getPosition(getLoc().m_x + 1, getLoc().m_y) 
            != penguin::getID())
        {
          setLoc(getLoc().m_x + 1, getLoc().m_y);
        }
        if (getLoc().m_y < closestFish.m_y 
            && s.getPosition(getLoc().m_x, getLoc().m_y + 1) 
            != penguin::getID())
        {
          setLoc(getLoc().m_x, getLoc().m_y + 1);
        }
        if (getLoc().m_x > closestFish.m_x 
            && s.getPosition(getLoc().m_x - 1, getLoc().m_y) 
            != penguin::getID())
        {
          setLoc(getLoc().m_x - 1, getLoc().m_y);
        }
        if (getLoc().m_y > closestFish.m_y 
            && s.getPosition(getLoc().m_x, getLoc().m_y - 1) 
            != penguin::getID())
        {
          setLoc(getLoc().m_x, getLoc().m_y - 1);
        }
      }
      // random movement if no fish found
      else
      {
        short direction;
        loc newLoc;
        direction = rand() % MOVEABLE_TILES;

        switch(direction)
        {
          case 0:       //top left
            newLoc.set(getLoc().m_x -1, getLoc().m_y+1);
            break;
          case 1:       //top middle
            newLoc.set(getLoc().m_x, getLoc().m_y+1);
            break;
          case 2:       //top right
            newLoc.set(getLoc().m_x +1, getLoc().m_y+1);
            break;
          case 3:       //right middle
            newLoc.set(getLoc().m_x +1, getLoc().m_y);
            break;
          case 4:       //right bottom
            newLoc.set(getLoc().m_x +1, getLoc().m_y-1);
            break;     
          case 5:       //midde bottom
            newLoc.set(getLoc().m_x -1, getLoc().m_y);
            break;
          case 6:       //left bottom
            newLoc.set(getLoc().m_x -1, getLoc().m_y-1);
            break;
          case 7:       //left middle
            newLoc.set(getLoc().m_x -1, getLoc().m_y);
            break;
        }

        if(s.isFull(newLoc) == false
            && newLoc.m_x < s.getSize() 
            && newLoc.m_y < s.getSize() 
            && newLoc.m_x >= 0
            && newLoc.m_y >= 0)
        {
          setLoc(newLoc);

        }
      }
      // eat fish
      if(getLoc() == closestFish)
      {
        hasEaten = true;
        for(short j = 0;j < s.getNumFish();j++)
        {
          if(closestFish == s.getFish(j).getLoc())
          {
            m_health += s.getFish(j).getFood();
            if (m_health > MAX_HEALTH)
              m_health = MAX_HEALTH;

            if(m_health > MIN_SPAWNING_HEALTH)
            {
              s.newPenguin();
              m_health /= 2;
            }
           s.setFish(j, s.getFish(s.getNumFish() - 1));            
           s.killFish();
          }
        }
      }
    }
    // Move away from whale if it cant see any fish.
    else
    {
      if (getLoc().m_x < closestWhale.m_x 
          && getLoc().m_x > 0 
          && s.getPosition(getLoc().m_x - 1, getLoc().m_y) != penguin::getID())
      {
        setLoc(getLoc().m_x - 1, getLoc().m_y);
      }
      if (getLoc().m_y < closestWhale.m_y 
          && getLoc().m_y > 0 
          && s.getPosition(getLoc().m_x, getLoc().m_y - 1) != penguin::getID())
      {
        setLoc(getLoc().m_x, getLoc().m_y - 1);
      }
      if (getLoc().m_x > closestWhale.m_x 
          && getLoc().m_x < s.getSize() - 1 
          && s.getPosition(getLoc().m_x + 1, getLoc().m_y) != penguin::getID())
      {
        setLoc(getLoc().m_x + 1, getLoc().m_y);
      }
      if (getLoc().m_y > closestWhale.m_y 
          && getLoc().m_y < s.getSize() - 1 
          && s.getPosition(getLoc().m_x, getLoc().m_y + 1) != penguin::getID())
      {
        setLoc(getLoc().m_x, getLoc().m_y + 1);
      }
    }
    m_health--;
    counter++;
  } while(counter < numMoves && !hasEaten);
}

const char penguin::m_charID = 'P';
