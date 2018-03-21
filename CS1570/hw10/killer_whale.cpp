// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: killer_whale.cpp
// Desc: Implementation file for killer_whale.h

#include "killer_whale.h"
#include <cmath>


void killer_whale::setLoc(const loc l)
{
  m_loc.set(l.m_x, l.m_y);
  return;
}

void killer_whale::setLoc(const short x, const short y)
{
  m_loc.set(x, y);
  return;
}

void killer_whale::move(sea & s)
{
  // starts closest at irrelevant location
  loc closest(s.getSize(), s.getSize());
  // Find closest penguin to whale
  for (int j = 0; j < s.getSize(); j++)
  {
    for (int k = 0; k < s.getSize(); k++)
    {
      loc newLoc(j,k);
      if (distLoc(getLoc(), newLoc) < distLoc(getLoc(), closest) 
          && s.getPosition(j,k) == penguin::getID())
      {
        closest = newLoc;
      }
    }
  }
  short counter = 0;
  bool hasEaten = false;
  do
  {
    if (getLoc().m_x < closest.m_x  && getLoc().m_x < s.getSize() - 1 
        && s.getPosition(getLoc().m_x + 1, getLoc().m_y) 
        != killer_whale::getID())
      setLoc(getLoc().m_x + 1, getLoc().m_y);
    
    if (getLoc().m_y < closest.m_y && getLoc().m_y < s.getSize() - 1 
        && s.getPosition(getLoc().m_x, getLoc().m_y + 1) 
        != killer_whale::getID())
      setLoc(getLoc().m_x, getLoc().m_y + 1);
    
    if (getLoc().m_x > closest.m_x && getLoc().m_x > -1 
        && s.getPosition(getLoc().m_x - 1, getLoc().m_y) 
        != killer_whale::getID())
      setLoc(getLoc().m_x - 1, getLoc().m_y);
    
    if (getLoc().m_y > closest.m_y && getLoc().m_y > -1 
        && s.getPosition(getLoc().m_x, getLoc().m_y - 1) 
        != killer_whale::getID())
      setLoc(getLoc().m_x, getLoc().m_y - 1);

    if(getLoc() == closest)
    {
      hasEaten = true;
      m_penguinsEaten++;
      for(short j = 0;j < s.getNumPenguins();j++)
      {
        if(closest == s.getPenguin(j).getLoc())
        {
          s.setPenguin(j, s.getPenguin(s.getNumPenguins() - 1));
          s.killPenguin();
        }
      }
    }
    counter++;
  } while (counter < NUM_WHALE_MOVES && !hasEaten);
}

float killer_whale::distLoc(loc p1, loc p2) const
{
  return sqrt((p2.m_x - p1.m_x)*(p2.m_x - p1.m_x) + (p2.m_y - 
    p1.m_y)*(p2.m_y - p1.m_y));
}

const char killer_whale::m_charID = 'K';
