/**
2. The C++ program given below is supposed to replace only the 1st occurrence 
   of either x or y with z in a 1D array of integers. For example, if x = 1, 
   y = 2, and z = 0, the array {1, 2} should become {0, 2}.
**/

#include <iostream>
using namespace std;

int main()						                    // line 1
{
  int x = 1;
  int y = 2;
  int z = 0;
  int a[2] = {1, 2};
  int arraySize = 2;

  for (int i = 0; i < arraySize; i++)			// line 2
  {
    if (a[i] == x)					              // line 3
    {
      a[i] = z;	                          // line 4
      i++;
    }							                        // line 5
    else if (a[i] == y)					          // line 6
    {
      a[i] = z;						                // line 7
      i++;
    }							                        // line 8
  }							                          // line 9

  // Output results

  for (int i = 0; i < arraySize; i++)
    cout << a[i] << " ";
  cout << endl;

  return(0);						                  // line 10
}
