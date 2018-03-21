//
//
//
//

#ifndef STACK_H
#define STACK_H

// Desc: The stack() constructs a stack.
// Pre:  None.
// Post: A stack is constructed.

// Desc: The push() adds a item to the stack.
// Pre:  None.
// Post: An item is added to the stack.

// Desc: The pop() removes an item from the stack.
// Pre:  None.
// Post: An item is removed from the stack.

// Desc: The top() returns the top item on the stack.
// Pre:  None.
// Post: The top item is returned.

// Desc: The size() returns the number of items in the stack.
// Pre:  None.
// Post: Number of items in the stack is returned.

const int SIZE = 256;

template<class T>
class stack
{
  private:
    T m_data[SIZE];
    int m_numData;
  public:
    stack():m_numData(0){}

    void push(const T& item);
    T pop();
    T top() const;
    int size() const;

};

#include "stack.hpp"
#endif
