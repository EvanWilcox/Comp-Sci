/*
* Author: Evan Wilcox
* File: knapSack.cpp Date: 4/4/2019
* Class: CS 2500 Sec. 1
* Instructor : Bruce McMillin
* Implementation file for three solutions to the 0-1 knapSack
*/

#include "knapSack.h"


int compare(const void * a, const void * b)
{
  double r1 = (double)(*(Item*)a).m_val / (*(Item*)a).m_wt;
  double r2 = (double)(*(Item*)b).m_val / (*(Item*)b).m_wt;

  if( r1 <  r2 )
  {
    return 1;
  } 
  else if( r1 >  r2 ) 
  {
    return -1;
  } 
  else
  {
    return 0;
  }
}


int greedyKnapSack(int W, struct Item arr[], int n)
{
  qsort(arr, n, sizeof(arr[0]), compare);
  
  int curWeight = 0;
  double finalvalue = 0.0;

  for(int i = 0; i < n; i++)
  {
    if(curWeight + arr[i].m_wt <= W)
    {
      curWeight += arr[i].m_wt;
      finalvalue += arr[i].m_val;
    }
  }

  return finalvalue;
}


int knapSack(int W, int wt[], int val[], int n)
{
  if(n == 0 || W == 0)
  {
    return 0;
  }

  if(wt[n-1] > W)
  {
    return knapSack(W, wt, val, n-1);
  }
  else
  {
    return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
  }
}


int iterativeKnapSack(int W, int wt[], int val[], int n)
{
  int i, w;

  int** K = new int*[n+1];
  for(int j = 0; j < n+1 ; j++)
  {
    K[j] = new int[W+1];
  }

  for(i = 0; i <= n ; i++)
  {
    for (w = 0; w <= W ; w++)
    {
      if(i == 0 || w == 0)
      {
        K[i][w] = 0;
      }
      else if(wt[i-1] <= w)
      {
        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
      }
      else
      {
        K[i][w] = K[i-1][w];
      }
    }
  }

  for(int j = 0; j < n+1 ; j++)
  {
    delete K[j];
  }
  delete K;

  return K[n][W];
}


int max(int a, int b)
{
  return (a > b) ? a : b;
}
