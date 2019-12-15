/*
* Author: Evan Wilcox
* File: knapSack.h Date: 4/4/2019
* Class: CS 2500 Sec. 1
* Instructor : Bruce McMillin
* Header file for knapSack.cpp
*/

#ifndef KNAPSACK_H
#define KNAPSACK_H

using namespace std;

/*
* Struct: Item
* A pairing of an item's weight and value.
*/
struct Item
{
  int m_val;
  int m_wt;

  Item(int val, int wt) : m_val(val), m_wt(wt){}
  Item() : m_val(0), m_wt(0){}
};

/*
* Function: compare
* Description: function used to compare two items by their m_val/m_wt
* Pre: a.m_wt != 0 and b.m_wt != 0
* Post: an int is returned
* Param a : an item
* Param b : an item
* Return:  1 if a's m_val/m_wt is less than b's,
          -1 if b's m_val/m_wt is greater than a's,
           0 if they are equal
*/
int compare(const void * a, const void * b);

/*
* Function: greedyKnapSack
* Description: a greedy implementation of the 0-1 knapsack
* Pre: W >= 0, arr[i].m_wt > 0, n >= 0
* Post: arr is sorted by arr[i].m_val/arr[i].m_wt ratio
* Param W : capacity remaining in the knapsack
* Param arr : array of items to try and put in the knapsack
* Param n : index of item in arr to try and put in the knapsack
* Return: greedy approximate to 0-1 knapsack problem
*/
int greedyKnapSack(int W, struct Item arr[], int n);

/*
* Function: knapSack
* Description: recursive implementation of the 0-1 knapsack
* Pre: W >= 0, wt[i] > 0, n >= 0
* Post: none
* Param W : capacity remaining in the knapsack
* Param wt : array of weights of items
* Param val : array of values of items
* Param n : index of item in wt/val to try and put in the knapsack
* Return: solution to knapsack problem
*/
int knapSack(int W, int wt[], int val[], int n);

/*
* Function: iterativeKnapSack
* Description: iterative implementation of the 0-1 knapsack
* Pre: W >= 0, wt[i] > 0, n >= 0
* Post: none
* Param W : capacity remaining in the knapsack
* Param wt : array of weights of items
* Param val : array of values of items
* Param n : index of item in wt/val to try and put in the knapsack
* Return: solution to knapsack problem
*/
int iterativeKnapSack(int W, int wt[], int val[], int n);

/*
* Function: max
* Description: A simple max function
* Pre: none
* Post: an int is returned
* Param a : an int
* Param b : an int
* Return: a if a > b, otherwise b
*/
int max(int a, int b);

#endif