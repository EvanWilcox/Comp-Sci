Programming assignment 7 (PA07)
==============================

Now that you have the basics of h, hpp, and cpp file management down, you can implemnent this assignment from scratch and test it from scratch. 

### You are required to submit 3 files:
* MyHeap.h - with a templated class named MyHeap
* my_sort.h - with a templated function called my_sort
* my_is_sorted.h - with a templated function called my_is_sorted

You are not required to have any hpp files, but you can.

You should not use a separate cpp implementation file(s) this time, just including everything in the h and/or hpp files.

### You will implement a priority queue (the abstract data type) using a max-heap (the data structure).

http://en.cppreference.com/w/cpp/container/priority_queue

The priority_que has few functions, and you will implement the following for MyHeap:
* default constructor - starts with an empty array
* parameterized constructor - takes two parameters, one templated array, and an integer size of the array. The constructor should build the internal heap using the heapify operation we learned. Note the syntax of this constructor differs from the std:: constructor.
* copy contructor
* destructor
* operator=
* top
* pop
* push
* empty
* size
* any internal functions you like (reserve, shrink_to_fit, etc.)

The behavior, return types, and parameters of the top, pop, push, empty, and size should be congruent with those of the std::priority_queue.

You WILL need to have internal functions to dynamically reserve more space for your array if it fills up, and if it becomes less than 1/4 full, to shrink the internal array size to fit.

### Next, you will build two functions, is_sorted() and sort().
The sort function can use whatever algorithm you want, but it would be easy to use the heap operations to implement your sort if you want.
These functions are generally modeled after:

http://en.cppreference.com/w/cpp/algorithm/sort

http://en.cppreference.com/w/cpp/algorithm/is_sorted

The sort functions will be much simpler (and diffirent than) the std:: versions.
* sort should take two parameters, a templated array, and an integer representing the size of the array. It should have void return type. The array that is passed should then be sorted by the function. The array should be sorted max-first.
* is_sorted should take the same two parameters, and return a bool, true if the array is sorted, and false if not. 

The sort functions will be graded for speed (the last 5 points of your grade, with 95% for correct functioning of everything else).


# General notes

The files listed here are the starting point for your assignment. 
Only add source files (not compiled files) to the Git repository.

Remember, the assignment due date is posted on the course website:
https://web.mst.edu/~taylorpat/Courses_files/DataStructures/Content.html

Git commands and a Git cheatsheet are posted at the following link, under the heading "Programming Assignments":
http://web.mst.edu/~taylorpat/Courses_files/DataStructures/Syllabus.html

