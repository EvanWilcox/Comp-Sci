///////////////////////////////////////////////
// @file   main.cpp
// @author Evan Wilcox
// @brief  Program used to test the Sort Class
///////////////////////////////////////////////

#include <iostream>
#include "Sort.h"
#include <random>
#include <time.h>
using namespace std;

int main()
{  
  Sort S;
  S.setDebug(true);

  const unsigned long MAX_SIZE = 1000000000;

  int *A = new int[MAX_SIZE];
  int *B = new int[MAX_SIZE];
  int *C = new int[MAX_SIZE];

  int rInt;
  clock_t t;

  unsigned n = 10;
  unsigned k = n;
  
  // Testing the algorithms with arrays of random integers to find average runtime.
  for( ; n < 10000; n+=k)
  {
    cout << "n = " << n << endl;

    for(unsigned j = 0; j < n; j++)
    {
      rInt = rand() % (n*10);
      A[j] = rInt;
      B[j] = rInt;
      C[j] = rInt;
    }

    t = clock();
    S.mergeSort(A, 0, n-1);
    cout << "MergeSort: " << (float)(clock()-t)/CLOCKS_PER_SEC << endl;

    t = clock();
    S.heapSort(B, n);
    cout << "HeapSort:  " << (float)(clock()-t)/CLOCKS_PER_SEC << endl;

    t = clock();
    S.quickSort(C, 0, n-1);
    cout << "QuickSort: " << (float)(clock()-t)/CLOCKS_PER_SEC << endl << endl;

    if(n == k*10)
    {
      k = n;
    }
  }
  

  n = 10;
  k = n;
  // Testing the algorithms with sorted arrays to find best/worst runtime.
  for( ; n < MAX_SIZE; n+=k)
  {
    cout << "n = " << n << endl;

    for(unsigned j = 0; j < n; j++)
    {
      A[j] = j;
      B[j] = n-j;
      C[j] = j;
    }

    t = clock();
    S.mergeSort(A, 0, n-1);
    cout << "MergeSort: " << (float)(clock()-t)/CLOCKS_PER_SEC << endl;

    t = clock();
    S.heapSort(B, n);
    cout << "HeapSort:  " << (float)(clock()-t)/CLOCKS_PER_SEC << endl;

    t = clock();
    S.quickSort(C, 0, n-1);
    cout << "QuickSort: " << (float)(clock()-t)/CLOCKS_PER_SEC << endl << endl;

    if(n == k*10)
    {
      k = n;
    }
  }

  delete A;
  delete B;
  delete C;

  return 0;
}
