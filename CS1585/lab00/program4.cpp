/**
  4. The C++ program given below is supposed to “flatten” and reverse the order 
  of the elements of a given 2D array.  By “flatten” we mean a n x m 2D array 
  should become a vector of  n * m elements. For example, {{1, 2}, {3, 4}, 
  {5, 6}} should become {6, 5, 4, 3, 2, 1}.
 **/

#include <iostream>
using namespace std;

int main()						                                  // line 1
{
  int rowSize = 3;
  int colSize = 2;
  int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int b[6] = {0,0,0,0,0,0};
  int k;
  int m;
  int m_last = -1;

  for (int i = 0; i < rowSize; i++)			                // line 2
  {
    for (int j = 0; j < colSize; j++)			            // line 3
    {
      m = i * rowSize-1 + j; 				                    // line 4
      if ((m >= rowSize * colSize) || (m <= m_last))	  // line 5
      {
        m = 1;						                              // line 6
      }						                                    // line 7
      k = rowSize * colSize - m - 1;			              // line 8
      b[k] = a[i][j];					                        // line 9
      m_last = m;					                            // line 10
    }							                                    // line 11
  }							                                        // line 12
/*
  int l = 0;
  for(int i = rowSize-1; i >= 0;i--)
  {
    for(int j = colSize-1;j >= 0;j--)
    {
      b[l] = a[i][j];
      l++;
    }
  }
*/


  // Output results

  for (int i = 0; i < (rowSize * colSize); i++)
    cout << b[i] << " ";
  cout << endl;

  return(0);						                                // line 13
}
