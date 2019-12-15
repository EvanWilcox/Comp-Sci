////////////////////////////////////////////////////
// @file   Sort.cpp
// @author Evan Wilcox
// @brief  Function definitions for the Sort class
////////////////////////////////////////////////////

#include "Sort.h"

void Sort::swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


bool Sort::checkSort(int arr[], int l, int r)
{
  // Precondition
  if(debug)
  {
    assert(0 <= l);
    assert(l <= r);
  }
  
  for(int i = l; i < r-1; i++)
  {
    if(arr[i] > arr[i+1])
    {
      return false;
    }
  }

  return true;
}


bool Sort::checkHeap(int arr[], int heapSize, int i)
{
  // Precondition
  if(debug)
  {
    assert(0 <= heapSize);
    assert(0 <= i);
  }
  
  if((i * 2 + 1) < heapSize)
  {
    if(arr[i*2+1] > arr[i])
    {
      return false;
    }
  }

  if((i * 2 + 2) < heapSize)
  {
    if(arr[i*2+2] > arr[i])
    {
      return false;
    }
  }

  return true;
}


void Sort::merge(int arr[], int l, int m, int r)
{
  // Preconditions
  if(debug)
  {
    assert(0 <= l);
    assert(l <= m);
    assert(m <= r);
    assert(checkSort(arr, l, m));
    assert(checkSort(arr, m+1, r));
  }


  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int *L = new int[n1];
  int *R = new int[n2];

  for(i = 0; i < n1; i++)
  {
    L[i] = arr[l+i];
  }
  for(j = 0; j < n2; j++)
  {
    R[j] = arr[m+1+j];
  }

  i = 0;
  j = 0;
  k = l;
  
  ////////////////////////////////////////////
  // merges the arrays L and R in to arr 
  // loop precondition:  arrays L and R are in sorted increasing order
  // loop postconsition: arr[l..r] is in increasing order
  // ivariant: arr[l..k] contains the smalest elements from 
  //           L and R in increasing order
  // proof:
  //    initialization: before the loop k=l so the subarry arr[l..k] 
  //                    has no elements so it is sorted
  //
  //    maintenance: either an element from L or R gets moved to arr
  //                 and k increases each iteration so arr[l..k] still 
  //                 contains elements from L and R
  //
  //    termination: at termination k = r so the subarry arr[l..r] contains 
  //                 the smallest elements from L and R at termination
  //
  ///////////////////////////////////////////
  while(i < n1 && j < n2)
  {
    // Invariant
    if(debug)
    {
      assert(checkSort(arr, l, k));
    }
    
    if(L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete L;
  delete R;

  // Postcondiion
  if(debug)
  {
    assert(checkSort(arr, l, r));
  }
}


void Sort::heapify(int arr[], int n, int i)
{
  // Preconditions
  if(debug)
  {
    assert(n >= 0);
    assert(i >= 0);
  }
  
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l < n && arr[l] > arr[largest])
  {
    largest = l;
  }

  if(r < n && arr[r] > arr[largest])
  {
    largest = r;
  }

  if(largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }

  // Postcondition
  if(debug)
  {
    assert(checkHeap(arr, n, largest));
  }
}


int Sort::partition(int arr[], int l, int h)
{
  // Precondition
  if(debug)
  {
    assert(0 <= l);
    assert(l <= h);
  }
  
  int x = arr[h];
  int i = (l - 1);

  for(int j = l; j <= h-1; j++)
  {
    if(arr[j] <= x)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i+1], &arr[h]);
  return (i+1);
}


Sort::Sort()
{
  debug = false;
}


Sort::Sort(bool b)
{
  debug = b;
}


void Sort::setDebug(bool b)
{
  debug = b;
}


void Sort::print(int arr[], int n)
{
  // Precondition
  if(debug)
  {
    assert(0 <= n);
  }
  
  for(int i = 0; i < n-1; i++)
  {
    cout << arr[i] << ", ";
    if((i+1) % 10 == 0)
    {
      cout << endl;
    }
  }

  cout << arr[n-1] << endl << endl;
}


void Sort::mergeSort(int arr[], int l, int r)
{
  // Preconditions
  if(debug)
  {
    assert(0 <= l);
    assert(l <= r);
  }
  
  if(l < r)
  {
    int m = l+(r-l)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
  }

  // Postcondition
  if(debug)
  {
    assert(checkSort(arr, l, r));
  }
}


void Sort::heapSort(int arr[], int n)
{
  // Preconditions
  if(debug)
  {
    assert(0 <= n);
  }
  
  ////////////////////////////////////////////
  // this for loop builds a max heap
  // loop precondition:  n is the number of elements in arr
  // loop postconsition: arr is not a max heap
  // ivariant: the nodes i+1, i+2, .., n are roots of 
  //           a max heap
  // proof:
  //    initialization: i = n/2 so the nodes n/2 +1, n/2 +2,
  //                    ..., n are leafs so are trivial roots of
  //                    max heaps
  //
  //    maintenance: the children of i are numbered higher than i,
  //                 by the loop invariant they are both roots of max heaps
  //                 decrementing i restablishes the invariant
  //
  //    termination: at termination i = -1, each node 1, 2, 3 are 
  //                 roots of max heaps
  //
  ///////////////////////////////////////////
  for(int i = n/2 - 1;i >= 0; i--)
  {
    heapify(arr, n, i);

    // Invariant
    if(debug)
    {
      for(int j = n/2; j < n; j++)
      {
        assert(checkHeap(arr, n, j));
      }
    }
  }
  
  for(int i = n-1; i >= 0; i--)
  {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }

  // Postcondition
  if(debug)
  {
    assert(checkSort(arr, 0, n));
  }
}


void Sort::quickSort(int arr[], int l, int h)
{
  // Preconditions
  if(debug)
  {
    assert(0 <= l);
    assert(l <= h);
  }
  
  if(l < h)
  {
    int p = partition(arr, l, h);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, h);
  }

  // Postcondition
  if(debug)
  {
    assert(checkSort(arr, l, h));
  }
}
