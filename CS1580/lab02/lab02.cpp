// Programmer: Evan Wilcox                  Date: 8/30/2017
// File: lab2.cpp                    	    Class: CS1580E

#include <iostream>
using namespace std;

int main()
{

  float monthlySavings; 
  char currency = '$';
  float monthlyIncome;
  float monthlyExpenses;
  
  // display brief welcome message
  cout << "Hey there, Let's Calculate Savings!!!" << endl;
  
  // read input from the user
  cout << "Enter your Income" << endl;
  cin >> monthlyIncome;
  
  
  cout << "Enter your monthly expenses" << endl;
  cin >> monthlyExpenses;
  
  // Calculating your savings...
  monthlySavings = monthlyIncome - monthlyExpenses;
  
  // display the result
  cout << "This month you saved..." << monthlySavings << currency << endl;
  
  return 0; 
}
