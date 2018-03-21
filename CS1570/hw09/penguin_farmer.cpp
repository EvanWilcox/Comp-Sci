// Name: Evan Wilcox      Date: 11/15/17
// Class: CS1570          Section: B
// Filename: penguin_farmer.cpp
// Desc: Function implementation file for penguin_farmer.h.

#include "penguin_farmer.h"

bool penguin_farmer::feed(penguin& p)
{
  bool fed = false;

  const float FEED_MAX = 3.0;
  const float FEED_MIN = 2.0;

  float foodToFeed = FEED_MIN + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(FEED_MAX-FEED_MIN)));

  if(m_food > foodToFeed)
  {
    fed = p.eat(foodToFeed);
    m_food -= foodToFeed;
  }
  else if(m_food < foodToFeed)
  {
    fed = p.eat(m_food);
    m_food -= m_food;
  }
  yell(fed);
  return fed;
}

void penguin_farmer::yell(const bool fed)
{
  if(!fed)
  {
    cout << "OUCH!! you dirty bird!\"....or something like that." << endl;
    m_timesBitten++;
  }
  return;
}

ostream& operator <<(ostream& os, const penguin_farmer pf)
{
  os << pf.m_name << " has " << pf.m_food << " lbs of food and $" <<pf.m_money << " dollars.";
  return os;
}

int penguin_farmer::getTimesBitten() const
{
  return m_timesBitten;
}
