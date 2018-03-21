//
//
//
//

#include "stack.h"

template<class T>
void stack<T>::push(const T& item)
{
  m_data[m_numData] = item;
  m_numData++;
}

template<class T>
T stack<T>::pop()
{
  m_numData--;
  return m_data[m_numData];
}

template<class T>
T stack<T>::top() const
{
  return m_data[m_numData-1];
}

template<class T>
int stack<T>::size() const
{
  return m_numData;
}
