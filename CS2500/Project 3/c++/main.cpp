/*
* Author: Evan Wilcox
* File: main.cpp Date: 4/4/2019
* Class: CS 2500 Sec. 1
* Instructor : Bruce McMillin
* Main file for Project 3
*/

#include <iostream>
#include <fstream>
#include "knapSack.h"
#include <time.h>
using namespace std;


int main()
{
  ofstream fout;
  fout.open("out.csv");
  
  const int MAX = 100000;

  int val[MAX];
  int wt[MAX];

  Item arr[MAX];
  int W = 50;

  clock_t t;
  fout << "N," << "KnapSack," << "Greedy," << "Iterative," << endl;

  int n;
  for(n = 10; n < MAX; n++)
  {
    for(int i = 0; i < n; i++)
    {
      int v = (rand() % 100) + 51;
      int w = (rand() % 50) + 1;

      val[i] = v;
      wt[i] = w;

      arr[i].m_val = v;
      arr[i].m_wt = w;
    }

    fout << n << ",";
    cout << n << endl;

    t = clock();
    knapSack(W, wt, val, n);
    fout << (float)(clock()-t)/CLOCKS_PER_SEC << ",";

    t = clock();
    greedyKnapSack(W, arr, n);
    fout << (float)(clock()-t)/CLOCKS_PER_SEC << ",";

    t = clock();
    iterativeKnapSack(W, wt, val, n);
    fout << (float)(clock()-t)/CLOCKS_PER_SEC;

    fout << endl;
  }

  fout.close();

  return 0;
}
