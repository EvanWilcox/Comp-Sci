/**
1. The C++ program given below is supposed to sort a 1D array of integers into 
   ascending order. For example, {3, 2, 1} should become {1, 2, 3}.
**/

#include <iostream>
using namespace std;

int main()						                          // line 1
{
  bool swapped = true;
  int a[5] = {5, 4, 3, 2, 1};
  int arraySize = 5;
  int num;

  while (swapped)					                      // line 2
  {
    swapped = false;					                  // line 3
    for (int i = 1; i <= arraySize-1; i++)			  // line 4
    {
      if (a[i-1] > a[i])					              // line 5
      {
        num = a[i];
        a[i] = a[i-1];					                // line 6
        a[i-1] = num;					                  // line 7
        swapped = true;				                  // line 8
      }						                              // line 9
    }							                              // line 10
  }							                                // line 11

  // Output results

  for (int i = 0; i < arraySize; i++)
    cout << a[i] << " ";
  cout << endl;

  return(0);						                        // line 12
}
