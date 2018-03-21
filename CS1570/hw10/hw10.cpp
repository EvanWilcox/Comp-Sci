// Name: Evan Wilcox && Nick Lacy     Date: 12/06/17
// Class: CS1570                      Section: B
// File Name: hw10.cpp
// Desc: Simulates a sea with fish, penguins, and killer whales.

#include <iostream>
#include "hw10.h"
#include "sea.h"
#include <unistd.h>
int main()
{
  sea mySea(SEA_SIZE);

  mySea.populate();
  mySea.setSpawnRate(SPAWN_RATE);

  bool shouldOutput;

  cout << "Do you want output?(0/1): ";
  cin >> shouldOutput;
  
  for(int i = 0;i < NUM_ITERATIONS;i++)
  {
    mySea.move();
    if(shouldOutput)
    {
      cout << '\n' << '\n' << '\n' << '\n';
      cout << "Iteration #" << i << endl;
      cout << mySea << endl;
      usleep(100000);
    }
  }

  cout << mySea << endl;

  return 0;
}


