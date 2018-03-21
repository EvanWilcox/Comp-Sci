// Name: EVAN WILCOX        Date: 9/27/17
// Class: CS1580            Section: E
// File: calculator.cpp 
// Description: calculator for adding, subtracting, or finding the
//              reverse of a number

#include <iostream>
using namespace std;

int addition(const int numOne, const int numTwo);
int subtraction(const int numOne, const int numTwo);
int reverse(int num);

int main() 
{
  int numOne;
  int numTwo;  
  int choice;

  cout << endl << "Welcome to the calculator. " << endl;
  cout << "  1. Addition" << endl;
  cout << "  2. Subtraction" << endl;
  cout << "  3. Reverse" << endl;
  cout << "What operation would you like to do?: ";
  cin >> choice;

  cout << endl << "Num 1: ";
  cin >> numOne;
  cout << endl << "Num 2: ";
  cin >> numTwo;

  switch(choice)
  {
    case 1:
      cout << "The addition of " << numOne << " and " << numTwo << " is "
        << addition(numOne, numTwo) << "." << endl;
      break;
    case 2:
      cout << "The subtractioin of " << numOne << " and " << numTwo
        << " is " << subtraction(numOne, numTwo) << "." << endl;
      break;
    case 3:
      cout << "The reverse of " << numOne << " is " << reverse(numOne)
        << "." << endl;
      break;
  }

  return 0;
}

int addition(const int numOne, const int numTwo)
{
  return numOne + numTwo;     // adds numOne to numTwo
}

int subtraction(const int numOne, const int numTwo)
{
  return numOne - numTwo;     // subtracts numTwo from numOne
}

int reverse(int num)
{
  int reverse;

  int i = (num % 10) * 100;   // gets first digit 
  num /= 10;
  int j = (num % 10) * 10;    // gets second digit
  num /= 10;
  int k = num;                // gets last digit

  return reverse = i + j + k;
}


