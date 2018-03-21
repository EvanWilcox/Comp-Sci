// Name: EVAN WILCOX		Date: 9/6/17
// Class: CS1580		Section: E
// File: diceGenerator.cpp
// Description: Converting random number to dice roll.

#include <iostream>
using namespace std;

int main()
{
  float userInput;		//float entered in by user
  const int NUM_OF_FACES = 6;	//constant number of faces on dice
  int diceRoll;			//calculated diceRoll from users input
  
  //Input
  cout << "Welcome to Dice Generator!" << endl;
  cout << "Enter a number between 0 and 1: ";
  cin >> userInput;
      
  //Calculations
  diceRoll = static_cast<int>(userInput*NUM_OF_FACES) + 1;
  
  //Output
  cout << "You rolled a " << diceRoll << endl;

  return 0;
} 
    
