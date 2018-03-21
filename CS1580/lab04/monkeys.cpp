// Name: EVAN WILCOX          Date: 9/13/2017
// Class: cs1580              Section: e
// File: monkeys.cpp
// Description: Monkeys jumping on the bed simulator



#include <iostream>
using namespace std;

int main()
{
  int num_of_monkeys = 5; 
  char input;

  cout << "Welcome to the Monkeys Jumping On The Bed Simulator. " << endl;

  do
  {
    cout << "There are " << num_of_monkeys << " monkeys jumping on the bed!"
      << " One fell off and bumped his head!" << endl
      <<  "Should the monkeys continue jumping? (y/n): " << endl;
    cin >> input;
    if(input == 'y')
      num_of_monkeys -= 1;
  }while(input == 'y' && num_of_monkeys > 0);  

  if(num_of_monkeys > 2)
  {
    cout << num_of_monkeys << " Monkeys bumped their heads! The total medical"
      << " bill is $" << 100.0 * num_of_monkeys << endl;  
  }
  else
  {
    cout << num_of_monkeys << " Monkeys bumped their heads! The total medical"
      << " bill is $" << 140.32*num_of_monkeys << endl;
  }

  cout << "Goodbye!" << endl;

  return 0;
}

