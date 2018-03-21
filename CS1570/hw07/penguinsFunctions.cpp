//Name: EVAN WILCOX       Date: 10/20/17
//Class: CS1570           Section: B
//Filename: penguinsFunctions.cpp
//Desc: 

#include "penguins.h"

int rand_wingSpan()
{
  return WINGSPAN_MIN + (rand() % (WINGSPAN_MAX - WINGSPAN_MIN + 1));
}

int rand_weight()
{
  return WEIGHT_MIN + (rand() % (WEIGHT_MAX - WEIGHT_MIN + 1));
}

float rand_neuroticism()
{
  return ((NEUROTICISM_MIN * 100) + (rand() % 
    (static_cast<int>((NEUROTICISM_MAX*100) - (NEUROTICISM_MIN*100)+1))))/100;
}

float rand_extroversion()
{
  return ((EXTROVERSION_MIN * 100) + (rand() % 
    (static_cast<int>((EXTROVERSION_MAX*100) - (EXTROVERSION_MIN*100)+1))))/100;
}

void print_penguin(const Penguin p)
{
  cout << "Name: " << p.m_name << "\tWingspan: " << p.m_physique.m_wingSpan
    << "\tWeight: " << p.m_physique.m_weight << "\tNeurosis: " 
    << p.m_personality.m_neuroticism << "\tExtroversion: " 
    << p.m_personality.m_extroversion << endl;
  return;
}

void print_penguins(const Penguin p[], const int num)
{
  for(int i = 0;i < num; i++)
    print_penguin(p[i]);
  return;
}

void print_penguins(const Penguin p[], const int index[], const int num)
{
  for(int i = 0;i < num;i++)
  {
    print_penguin(p[index[i]]);
  }
  return;
}

void randomize_penguins(Penguin p[])
{
  for(int i = 0;i < NUM_PENGUINS;i++)
  {
    p[i].m_name = NAMES[i];
    p[i].m_physique.m_wingSpan = rand_wingSpan();
    p[i].m_physique.m_weight = rand_weight();
    p[i].m_personality.m_neuroticism = rand_neuroticism();
    p[i].m_personality.m_extroversion = rand_extroversion();
  }
  return;
}

void sort(int dataArray[], int indexArray[], const int start)
{
  if(start == NUM_PENGUINS - 1)
  {
    return;
  }

  int index = start;

  for(int i = start + 1; i < NUM_PENGUINS;i++)
  {
    if(dataArray[i] < dataArray[index])
    {
      index = i;
    }
  }

  swap(indexArray[start], indexArray[index]);
  swap(dataArray[start], dataArray[index]);
  sort(dataArray, indexArray, start + 1);
}

void sort(float dataArray[], int indexArray[], const int start)
{
  if(start == NUM_PENGUINS - 1)
  {
    return;
  }

  int index = start;

  for(int i = start + 1; i < NUM_PENGUINS;i++)
  {
    if(dataArray[i] < dataArray[index])
    {
      index = i;
    }
  }

  swap(indexArray[start], indexArray[index]);
  swap(dataArray[start], dataArray[index]);
  sort(dataArray, indexArray, start + 1);
}

void get_wingSpan_array(const Penguin dataArray[], int copyArray[])
{
  for(int i = 0; i < NUM_PENGUINS; i++)
    copyArray[i] = dataArray[i].m_physique.m_wingSpan;
  return;
}

void get_neuroticism_array(const Penguin dataArray[], float copyArray[])
{
  for(int i = 0; i < NUM_PENGUINS; i++)
    copyArray[i] = dataArray[i].m_personality.m_neuroticism;
  return;
}

void create_index(int index[])
{
  for(int i = 0;i < NUM_PENGUINS;i++)
    index[i] = i;
  return;
}

Penguin get_superPenguin(const Penguin breeders[], const int numBreeders)
{
  Penguin p;
  p.m_name = SUPER_PENG_NAME;

  if(numBreeders > 1)
  {
    int avgWingSpan = 0;
    for(int i = 0;i<numBreeders;i++)
    {
      avgWingSpan += breeders[i].m_physique.m_wingSpan;
    }
    avgWingSpan /= numBreeders;
    p.m_physique.m_wingSpan = avgWingSpan * WINGSPAN_MULTIPLIER;

    int avgWeight = 0;
    for(int i = 0;i<numBreeders;i++)
    {
      avgWeight += breeders[i].m_physique.m_weight;
    }
    avgWeight /= numBreeders;
    p.m_physique.m_weight = avgWeight * WEIGHT_MULTIPLIER;

    float minNeurosis = breeders[0].m_personality.m_neuroticism;
    for(int i = 1;i< numBreeders;i++)
    {
      if(breeders[i].m_personality.m_neuroticism < minNeurosis)
        minNeurosis = breeders[i].m_personality.m_neuroticism;
    }
    p.m_personality.m_neuroticism = minNeurosis;

    p.m_personality.m_extroversion = rand_extroversion();
  }
  else
  {
    p.m_physique.m_wingSpan = breeders[0].m_physique.m_wingSpan;
    p.m_physique.m_weight = breeders[0].m_physique.m_weight;
    p.m_personality.m_neuroticism = breeders[0].m_personality.m_neuroticism;
    p.m_personality.m_extroversion = breeders[0].m_personality.m_extroversion;
  }

  return p;
}
