//
//
//
//

#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
  stack<int> myStack;

  int numItems;

  cout << "How many items should we put on the stack?: ";
  cin >> numItems;
  
  int item;
  
  for(int i = 0;i < numItems;i++)
  {
    cout  << "Item: ";
    cin >> item;
    myStack.push(item);
  }
  
  cout << "This is on the stack: " << endl;

  for(int i = 0;i < numItems;i++)
  {
    cout << myStack.pop() << endl;
  }

  return 0;
}
