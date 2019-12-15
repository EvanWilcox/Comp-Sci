#include <iostream>
#include "MyHeap.h"
#include "my_is_sorted.h"
#include "my_sort.h"

using std::cout;
using std::endl;


// This file is merely a rough guideline,
// and you should make your own for testing.
int main()
{
<<<<<<< Updated upstream
    // Heap
    MyHeap<int> q;

    cout << q.size() << endl;

    for(int k = 0; k < 10; k++)
        q.push(k);
=======
  // Heap
  MyHeap<int> q;

  cout <<  q.size() << endl;

  for(int k; k < 10; k++)
    q.push(k);

  cout << "size" << q.size() << endl;
>>>>>>> Stashed changes


<<<<<<< Updated upstream
    while(!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    int my_array[6] = {4, 6, 9, 12, 124, 4};
    MyHeap<int> q2(my_array, 6);    // parameterized constructor

    MyHeap<int> q3(q2);             // copy constructor
    MyHeap<int> q4 = q2;            // copy constructor
    MyHeap<int> q5;                 // default constructor
    q5 = q4;                        // operator=
=======
  while(!q.empty())
  {
    cout << "top" << q.top() << endl;
    q.pop();
  }

  int my_array[6] = {4, 6, 9, 12, 124, 4};

  MyHeap<int> q2(my_array, 6);    // parameterized constructor
  MyHeap<int> q3(q2);             // copy constructor
  MyHeap<int> q4 = q2;            // copy constructor
  MyHeap<int> q5;                 // default constructor
  q5 = q4;                        // operator=
>>>>>>> Stashed changes

  while(!q4.empty())
  {
    cout << q4.top() << endl;
    q4.pop();
  }

  // Sort
  int my_array2[6] = {4, 6, 9, 12, 124, 4};

<<<<<<< Updated upstream
    cout << my_is_sorted(my_array2, 6) << endl;
    my_sort(my_array2, 6);
    cout << my_is_sorted(my_array2, 6) << endl;
=======
  cout << my_is_sorted(my_array, 6) << endl;
  my_sort(my_array, 6);
  cout << my_is_sorted(my_array, 6) << endl;
>>>>>>> Stashed changes

  for(int k; k < 6; k++)
  {
    cout << my_array2[k] << endl;
  }

  return 0;
}

