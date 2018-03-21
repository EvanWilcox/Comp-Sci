// Name: Evan Wilcox      Date: 11/15/17
// Class: CS1570          Section: B
// Filename: penguin.cpp
// Desc: Function implementation file for penguin.h.

#include "penguin.h"

penguin::penguin(const string n, const float w, const int a)
{
  setName(n);
  setWeight(w);
  setAge(a);
}


void penguin::setName()
{
  const int NUM_NAMES = 10;

  ifstream fin("names.txt");
  string name;
  int num = 1 + (rand() % NUM_NAMES);
  int count  = 0;

  while(count < num)
  {
    fin >> name;
    count++;
  };
  m_name = name;

  fin.close();

  return;
}

void penguin::setName(const string n)
{
  m_name = n;
  return;
}

void penguin::setWeight(const float w)
{
  
  m_weight = (w > 0 ? w:DEFAULT_WEIGHT);
  return;
}

void penguin::setAge(const int a)
{
  const int MAX_AGE = 1000;
  m_age = (a > 0 && a <= MAX_AGE ? a:DEFAULT_AGE);
  return;
}

bool penguin::eat(const float f)
{
  bool ate = false;

  if(f)
  {
    const float EPSILON_MAX = 0.1;
    const float EPSILON_MIN = -0.05;

    float epsilon;
    epsilon = EPSILON_MIN + static_cast<float>(rand()) /(static_cast<float>(RAND_MAX/(EPSILON_MAX-EPSILON_MIN)));

    m_weight += 70000 * log(1 + (f * .02) * epsilon / ( 165 + m_age/5 ));
    ate = true;
    m_poop = poop(f);
  }

  m_age++;

  return ate;
}

float penguin::poop(const float f)
{
  const float POOP_PERCENT = 0.98;
  const float WEIGHT_LOST = 0.005 * m_weight;
  
  m_weight -= WEIGHT_LOST;
  return WEIGHT_LOST  + f * POOP_PERCENT;
}

ostream& operator <<(ostream& os, const penguin p)
{
  os << p.m_name << " weighs " << p.m_weight << " lbs and is " << p.m_age << " days old.";
  return os;
}

float penguin::getPoop() const
{
  return m_poop;
}
