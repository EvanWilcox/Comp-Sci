// Name: Evan Wilcox      Date: 11/15/17
// Class: CS1570          Section: B
// Filename: hw09.cpp
// Desc: Testing penguin class and penguin_farmer class.

#include "penguin.h"
#include "penguin_farmer.h"

int main()
{
  srand(time(NULL));

  const int NUM_PENGUINS = 5;
  const float MONEY_PER_POOP = 0.05;

  float totalPoop = 0;

  penguin p("Jerry", 7, 23);
  penguin h;
  cout << p << endl << h << endl;

  penguin_farmer pf("Hans", 4575, 0);
  cout << pf << endl << endl;


  penguin myPengs[NUM_PENGUINS];

  for(int h = 0;h < 365;h++)
  {
    for(int i = 0;i < NUM_PENGUINS;i++)
    {
      pf.feed(myPengs[i]);
      totalPoop += myPengs[i].getPoop();
    }
  }


  for(int i = 0;i < NUM_PENGUINS;i++)
  {
    cout << myPengs[i] << endl;
  }

  cout << endl << "Total poop: " << totalPoop << endl;
  cout << "Total money earned: " << ceilf(totalPoop * MONEY_PER_POOP*100)/100 << endl;
  cout << "Total times bitten: " << pf.getTimesBitten() << endl;

  return 0;
}
