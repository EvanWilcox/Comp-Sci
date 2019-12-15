/////////////////////////////////////////
// @file   Sort.h
// @author Evan Wilcox
// @brief  Header file for Sort.cpp
/////////////////////////////////////////

#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <assert.h>
using namespace std;

/////////////////////////////////////////
// @class Sort
// @brief Wrapper class for MergeSort, 
//        HeapSort, and QuickSort
/////////////////////////////////////////
class Sort
{
  private:
    bool debug;  // indictaes if debug mode is on

    /////////////////////////////////////////
    // @fn     swap
    // @brief  swaps the values at *a and *b
    // @pre    a and b are pointers
    // @post   the values of a* and b* are swapped
    // @param  a pointer to an int
    // @param  b pointer to an int
    // @return none
    /////////////////////////////////////////
    void swap(int *a, int *b);

    /////////////////////////////////////////
    // @fn     checkSort
    // @brief  checks if the passed array is in increasing order
    // @pre    0 <= l <= r
    // @post   true is returned if the subarry arr[l..r] is in increasing order
    // @param  arr the array containing the subarry to be checked
    // @param  l is the first index of the array to be checked
    // @param  r is the last index of the array to be cecked
    // @return bool b is true if the array is in increasing order
    /////////////////////////////////////////
    bool checkSort(int arr[], int l, int r);

    /////////////////////////////////////////
    // @fn     checkHeap
    // @brief  checks if the node i is a max heap
    // @pre    heapSize and i >= 0
    // @post   true is returned if the node i is a max heap
    // @param  arr the array containing the the node i
    // @param  heapSize the size of the heap in the the array arr
    // @praam  i the node that is being checked
    // @return returns true if the node i is a max heap
    /////////////////////////////////////////
    bool checkHeap(int arr[], int heapSize, int i);

    /////////////////////////////////////////
    // @fn     merge
    // @brief  merges two sorted subarrays
    // @pre    the subarrays arr[l..m] and arr[m+1..r] are in increasing order
    //         0 <= l <= m <= r
    // @post   the two subarrays are merged
    // @param  arr the array containing the subarrays to be sorted
    // @param  l left index of the first array
    // @param  m the middle index between the two subarrays
    // @param  r right index of the second subarray
    // @return none
    /////////////////////////////////////////
    void merge(int arr[], int l, int m, int r);

    /////////////////////////////////////////
    // @fn     heapify
    // @brief  turns the node i into a max heap
    // @pre    n and i >= 0
    // @post   the node i is a max heap
    // @param  arr the array containing the node i 
    // @param  n the heapsize of the heap in the array arr
    // @param  i the node to be turned into a max heap
    // @return none
    /////////////////////////////////////////
    void heapify(int arr[], int n, int i);

    /////////////////////////////////////////
    // @fn     partition
    // @brief  partitions the subarry arr[l..h]
    // @pre    0 <= l <= h
    // @post   the subarray arr[l..h] is partitioned
    // @param  arr the array containing the subarry to be pratitioned
    // @param  l the left index of the subarry
    // @param  h the right index of the subarray
    // @return the index of the element used as the partition
    /////////////////////////////////////////
    int partition(int arr[], int l, int h);

  public:
    /////////////////////////////////////////
    // @fn     Sort
    // @brief  default constructor
    // @pre    none
    // @post   Sort object is created
    // @return none
    /////////////////////////////////////////
    Sort();

    /////////////////////////////////////////
    // @fn     Sort
    // @brief  constructor that sets debug
    // @pre    none
    // @post   Sort object is created
    // @param  b the debug mode to be set
    // @return none
    /////////////////////////////////////////
    Sort(bool b);

    /////////////////////////////////////////
    // @fn     setDebug
    // @brief  changes the debug mode
    // @pre    none
    // @post   debug = b
    // @param  b the new debug mode
    // @return none
    /////////////////////////////////////////
    void setDebug(bool b); 

    /////////////////////////////////////////
    // @fn     print
    // @brief  prints out the given array
    // @pre    n >= 0
    // @post   arr is printed out using cout
    // @param  arr and array of integers
    // @param  n the length of arr
    // @return none
    /////////////////////////////////////////
    void print(int arr[], int n);

    /////////////////////////////////////////
    // @fn     mergeSort
    // @brief  recursive implementation of the quicksort algorithm
    // @pre    0 <= l <= r
    // @post   arr[l..r] is sorted in increasing order
    // @param  arr the array containing the subarry to be sorted
    // @param  l the left index of the subarry
    // @param  r the right index of the subarray
    // @return none
    /////////////////////////////////////////
    void mergeSort(int arr[], int l, int r);

    /////////////////////////////////////////
    // @fn     heapSort
    // @brief  recursive implementation of heapsort
    // @pre    n is the length of arr,
    //         0 <= n
    // @post   arr is in increasing order
    // @param  arr the array to be sorted
    // @param  n the length of arr
    // @return none
    /////////////////////////////////////////
    void heapSort(int arr[], int n);

    /////////////////////////////////////////
    // @fn     quickSort
    // @brief  recursive implementation of quicksort
    // @pre    0 <= l <= h
    // @post   arr[l..h] is in increasing order
    // @param  arr the array containing the subarry to be sorted
    // @param  l the left index of the subarry to be sorted
    // @param  h the right index of the subarry to be sorted
    // @return none
    /////////////////////////////////////////
    void quickSort(int arr[], int l, int h);
};

#endif
