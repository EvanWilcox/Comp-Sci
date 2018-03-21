// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: sea.cpp
// Desc: Implementation file for sea.h

#include <cmath>
#include "hw10.h"
#include "sea.h"
#include "fish.h"
#include "penguin.h"
#include "killer_whale.h"

sea::sea()
{
  m_size = MAX_SIZE;
  
  // crazy cool code
  m_kWhales = new killer_whale[MAX_WHALES];
  m_penguins = new penguin[MAX_PENGUINS];
  m_fishes = new fish[MAX_FISHES];

  for(int i = 0;i < m_size;i++)
  {
    for(int j = 0;j < m_size;j++)
    {
      m_theSea[i][j] = EMPTY;
    }
  }

  m_numFishAlive = START_NUM_FISH;
  m_numPenguinAlive = START_NUM_PENGUINS;
  m_numWhaleAlive = MAX_WHALES;
}

sea::sea(const short s)
{
  m_size = s;
  
  // crazy cool code
  m_kWhales = new killer_whale[MAX_WHALES];
  m_penguins = new penguin[MAX_PENGUINS];
  m_fishes = new fish[MAX_FISHES];
  
  for(int i = 0;i < m_size;i++)
  {
    for(int j = 0;j < m_size;j++)
    {
      m_theSea[i][j] = EMPTY;
    }
  }
  m_numFishAlive = START_NUM_FISH;
  m_numPenguinAlive = START_NUM_PENGUINS;
  m_numWhaleAlive = MAX_WHALES;
}

bool sea::isFull(const loc l) const
{
  bool full = false;

  if(m_theSea[l.m_x][l.m_y] != EMPTY)
    full = true;

  return full;
}

void sea::clear()
{
  for(int i = 0;i < m_size;i++)
  {
    for(int j = 0;j < m_size;j++)
    {
      m_theSea[i][j] = EMPTY;
    }
  }
}

void sea::update()
{
  clear();

  loc newLoc;

  for(int i = 0;i < m_numFishAlive;i++)
  {
    setPos(m_fishes[i]);
  }

  for(int i = 0;i < m_numPenguinAlive;i++)
  {
    setPos(m_penguins[i]);
  }

  for(int i = 0;i < m_numWhaleAlive;i++)
  {
    setPos(m_kWhales[i]);
  }
}

void sea::populate()
{
  loc newLoc;


  for(int i = 0;i < m_numFishAlive;i++)
  {
    bool valid = false;

    do
    {
      newLoc.set(rand() % m_size, rand() % m_size);

      if(isFull(newLoc) == false)
      {
        m_fishes[i].setLoc(newLoc);
        setPos(m_fishes[i]);
        valid = true;
      }
    } while(!valid);
  }

  for(int i = 0;i < m_numPenguinAlive;i++)
  {
    bool valid = false;

    do
    {
      newLoc.set(rand() % m_size, rand() % m_size);

      if(isFull(newLoc) == false)
      {
        m_penguins[i].setLoc(newLoc);
        setPos(m_penguins[i]);
        valid = true;
      }
    } while(!valid);
  }

  for(int i = 0;i < m_numWhaleAlive;i++)
  {
    bool valid = false;

    do
    {
      newLoc.set(rand() % m_size, rand() % m_size);

      if(isFull(newLoc) == false)
      {
        m_kWhales[i].setLoc(newLoc);
        setPos(m_kWhales[i]);
        valid = true;
      }
    } while(!valid);
  }
}

void sea::move()
{

  loc newLoc;
  fish newFish;
  // spawn new fish
  for(int i = 0;i < m_numNewFish;i ++)
  {
    if(m_numFishAlive < MAX_FISHES)
    {
      do 
      {
        newLoc.set(rand() % m_size, rand() % m_size);
      } while(isFull(newLoc));
      newFish.setLoc(newLoc);
      addFish(newFish);
    }
  }

  for(int i = 0;i < m_numFishAlive;i++)
  {
    m_fishes[i].move(*this);
    update();
  }

  // moves penguins
  for(int i = 0;i < m_numPenguinAlive;i++)
  {
    m_penguins[i].move(*this);
    update();
  }

  for(int i = 0;i < m_numWhaleAlive;i++)
  {
    m_kWhales[i].move(*this);
    update();
  }

  return;
}

char sea::getPosition(const int x, const int y) const
{
  return m_theSea[x][y];
}

void sea::newPenguin()
{
  if(m_numPenguinAlive < MAX_PENGUINS)
  {
    penguin newP;
    loc newLoc;

    do
    {
      newLoc.set(rand() % m_size, rand() % m_size);
    } while(isFull(newLoc));

    newP.setLoc(newLoc);
    m_penguins[m_numPenguinAlive] = newP;
    m_numPenguinAlive++;
  }
  return;
}

ostream& operator <<(ostream& os, const sea& s)
{
  cout << "Number of Penguins: " << s.m_numPenguinAlive << endl;
  cout << "Number of Fish: " << s.m_numFishAlive << endl;
  cout << "Fish spawn rate: " << SPAWN_RATE << endl;
  for(int i = 0;i < s.m_numWhaleAlive;i++)
  {
    cout << "Whale " << (i+1) << " kills: " 
      << s.m_kWhales[i].getPenguinsEaten() << endl;
  }
  cout << "|";
  for(int i = 0;i < s.m_size;i++)
  {
    cout << "==";
  }
  cout << "|" << endl;
  for(int i = s.m_size-1;i >= 0;i--)
  {
    cout << "|";
    for(int j = 0;j < s.m_size;j++)
    {
      os << s.m_theSea[j][i] << " ";
    }
    os << "|" << endl;
  }
  cout << "|";
  for(int i = 0;i < s.m_size;i++)
  {
    cout << "==";
  }
  cout << "|";
  return os;
}

void sea::addFish(const fish f)
{
  m_fishes[m_numFishAlive] = f;
  m_numFishAlive++;
  return;
}

void sea::killFish()
{
  m_numFishAlive--;
  return;
}
void sea::killPenguin()
{
  m_numPenguinAlive--;
  return;
}

float sea::distLoc(loc p1, loc p2) 
{
  return sqrt((p2.m_x - p1.m_x)*(p2.m_x - p1.m_x) + (p2.m_y - 
        p1.m_y)*(p2.m_y - p1.m_y));
}

fish sea::getFish(const short i) const
{
  return m_fishes[i];
}

penguin sea::getPenguin(const short i) const
{
  return m_penguins[i];
}

killer_whale sea::getWhale(const short i) const
{
  return m_kWhales[i];
}

void sea::setFish(const short i, const fish f)
{
  m_fishes[i] = f;
  return;
}

void sea::setPenguin(const short i, const penguin p) 
{
  m_penguins[i] = p;
  return;
}


void sea::setSpawnRate(const short spawnRate)
{
  m_numNewFish = spawnRate;
  return;
}
