// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: loc.cpp
// Desc: Implementation file for loc.h.

#include "loc.h"

bool loc::operator ==(const loc& rhs)
{
  bool isEqual = false;
  if(m_x == rhs.m_x && m_y == rhs.m_y)
  {
    isEqual = true;
  }
  return isEqual;
}
