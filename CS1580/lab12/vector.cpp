//Name: Evan Wilcox       Date: 11/8/17
//Class: CS1580           Section: E
//Filename: vector.cpp
//Desc: implementatino file for vector.h

#include "vector.h"

vector vector::operator +(const vector rhs) const
{
  vector result(*this);
  result.m_x += rhs.m_x;
  result.m_y += rhs.m_y;
  result.m_z += rhs.m_z;
  return result;
}

vector vector::operator -(const vector rhs) const
{
  vector result(*this);
  result.m_x -= rhs.m_x;
  result.m_y -= rhs.m_y;
  result.m_z -= rhs.m_z;
  return result;
}

ostream& operator <<(ostream& os, const vector v)
{
  os << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
  return os;
}

float vector::getX() const
{
  return m_x;
}

float vector::getY() const
{
  return m_y;
}

float vector::getZ() const
{
  return m_z;
}

void vector::setX(const float x)
{
  m_x = x;
  return;
}

void vector::setY(const float y)
{
  m_y = y;
  return;
}

void vector::setZ(const float z)
{
  m_z = z;
  return;
}

