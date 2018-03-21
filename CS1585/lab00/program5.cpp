/**
5. The C++ program given below is supposed to find the smallest 
   sequential subsequence of integers in a 1D array whose sum is zero 
   (if such a sequence exists). For example, in the array {2, 1, -1}, we 
   can start at (0-based) index position 1 and use a sequential sequence of 
   length 2 because 1 + -1 = 0. As another example, in the array {2, -1, 2}, 
   there is no sequential sequence whose sum is 0, in which case we output a 
   start position and sequence length of 0.
**/

#include <iostream>
using namespace std;
int main()								// line 1
{
  int arraySize = 3;
  int a[3] = {3, -2, -1};
  int sum;
  bool solutionFound;
  int sequenceSize;
  int start = 0;
  int solutionStartAt = 0;
  int solutionSequenceSize = 0;

  solutionFound = false;						// line 2
  sequenceSize = 1;							// line 3
  while ((! solutionFound) && (sequenceSize <= arraySize)) {		// line 4
    while ((! solutionFound) && (start+sequenceSize <= arraySize)) {	// line 5
      sum = 0;								// line 6
      for (int i = start; i < start+sequenceSize; i++) {			// line 7
        sum += a[i];							// line 8
      }								// line 9
      if (sum == 0) {							// line 10
        solutionFound = true;						// line 11
      }								// line 12
      else {
        start++;							// line 13
      }								// line 14
    }									// line 15
    if (solutionFound) {						// line 16
      solutionStartAt = start;						// line 17
      solutionSequenceSize = sequenceSize;				// line 18
    } 									// line 19
    else{
      start = 0;						// line 20
      sequenceSize++;	      // line 21
    }									// line 22
  }									// line 23

  // Output results
 
  cout << "start = " << solutionStartAt << " sequence length = "
    << solutionSequenceSize << endl;

  return(0);								// line 24
}
