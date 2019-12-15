
#ifndef MY_HEAP
#define MY_HEAP

template <typename T>
class MyHeap
{
  private:
    
    T *heap; 
    int maxSize;
    int numElements;
    
    void shrink();
    
    void grow();

    bool isLeaf(int i) const;

    int parent(int i) const;

  public:
    
    MyHeap();
    
    MyHeap(T init_array[], int init_size);
    
    MyHeap(const MyHeap<T> &source);
    
    ~MyHeap();
    
    MyHeap<T> operator=(const MyHeap<T> &source);
    
    T top() const;
    
    void pop();
    
    void push(T &val);
    
    bool empty();
    
    int size() const;
};

#include "MyHeap.hpp"

#endif
