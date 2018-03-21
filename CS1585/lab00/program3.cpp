/**
3. The C++ program given below is supposed to determine how many times you 
   can add a specified increment, staying under a specified maxSum and doing 
   no more than maxAdditions many additions. For example, if increment is 2, 
   maxAdditions is 4, and maxSum is 7, then you can only do 3 additions and 
   your resulting sum will be 6.
**/

#include <iostream>
using namespace std;

int main()						                    // line 1
{
  bool keepGoing = true;
  int sum = 0;
  int additions = 0;
  int maxSum = 7;
  int maxAdditions = 4;
  int increment = 2;

  while (keepGoing)					              // line 2
  {
    if (sum + increment > maxSum)				  // line 3
    {
      keepGoing = false;				          // line 4
    }							                        // line 5
    else
    {
      if (additions >= maxAdditions)			// line 6
      {
        keepGoing = false;				        // line 7
      }						                        // line 8
      else
      {
        sum += increment;				          // line 9
        additions++;					            // line 10
      }						                        // line 11
    }							                        // line 12
  }							                          // line 13

  // Output results

  cout << sum << endl;
  cout << additions << endl;

  return(0);						                  // line 14
}
