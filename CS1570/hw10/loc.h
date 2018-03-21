// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: loc.h
// Desc: Header file for loc.cpp

#ifndef LOC_H
#define LOC_H

const short DEAD_X = -1;              // x position of the dead characters
const short DEAD_Y = -1;              // y position of the dead characters

// Desc: The loc() sets the x and y variables to given parameters or defaults.
// Pre:  None.
// Post: Variables are set.

// Desc: The set() sets the x and y variables to given parameters.
// Pre:  None.
// Post: Variables are set.

// Desc: The operator ==() is the overloaded comparison operator.
// Pre:  None.
// Post: The comparison operator is overloaded.


struct loc
{
  short m_x;
  short m_y;

  loc():m_x(DEAD_X), m_y(DEAD_Y){}
  loc(const short x, const short y):m_x(x), m_y(y){}

  void set(const short x, const short y){m_x = x; m_y = y;}

  bool operator ==(const loc& rhs);
};

#endif
