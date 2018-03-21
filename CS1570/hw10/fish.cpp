// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: fish.cpp
// Desc: Implementation file for fish.cpp

#include "fish.h"


void fish::setLoc(const loc l)
{
  m_loc.set(l.m_x, l.m_y);
  return;
}


void fish::move(const sea& s)
{
  short direction;
  loc newLoc;
  bool isSet = false;
  short counter = 0;

  do 
  {
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
      isSet = true;
    }
  counter++;
  } while(!isSet && counter < MAX_NUM_TRIES);

}

const char fish::m_charID = 'F';
