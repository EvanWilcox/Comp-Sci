//
//
//
//


#include "meeseeks.h"
using namespace std;
meeseeks::meeseeks()
{
  m_ID = generateID();
  m_purpose = "";
}

int meeseeks::generateID()
{
  int newID;
  newID = ++m_numMeeseeks;
  return newID;
}

void meeseeks::setPurpose(const string p)
{
  m_purpose = p;
  return;
}

string meeseeks::getPurpose() const
{
  return m_purpose;
}

int meeseeks::getID() const
{
  return m_ID;
}

int meeseeks::m_numMeeseeks = 0;
