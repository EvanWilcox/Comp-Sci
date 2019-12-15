


template <typename T>
MyHeap<T>::MyHeap()
{
  heap = NULL;
  maxSize = 0;
  numElements = 0;
}


template <typename T>
MyHeap<T>::MyHeap(T init_array[], int init_size)
{
  maxSize = init_size * 3 / 2;
  numElements = init_size;

  heap = new T[maxSize];

  for(int i = 0;i < init_size;i++)
  {
    heap[i] = init_array[i];
  }
}


template <typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
  maxSize = source.numElements * 3 / 2;
  numElements = source.numElements;

  heap = new T[maxSize];

  for(int i = 0;i < numElements;i++)
  {
    heap[i] = source.heap[i];
  }
}


template <typename T>
MyHeap<T>::~MyHeap()
{
  if(heap != NULL)
  {
    delete[] heap;
  }
}


template <typename T>
MyHeap<T> MyHeap<T>::operator=(const MyHeap<T> &source)
{
  if(heap != NULL)
  {
    delete[] heap;
  }  
  
  maxSize = source.numElements * 3 / 2;
  numElements = source.numElements;

  heap = new T[maxSize];

  for(int i = 0;i < numElements;i++)
  {
    heap[i] = source.heap[i];
  }

  return *this;
}


template <typename T>
T MyHeap<T>::top() const
{
  if(numElements)
  {
    return heap[0];
  }
  else
  {
    //return 
  }
}


template <typename T>
void MyHeap<T>::pop()
{
  

  numElements--;

  if(numElements < maxSize/2)
  {
    shrink();
  }
}


template <typename T>
void MyHeap<T>::push(T &val)
{
  heap[numElements] = val;
  int pos = numElements++;

  while((pos != 0) && (heap[pos] < heap[parent(pos)]))
  {
    std::swap(heap[pos], heap[parent(pos)]);
    pos = parent(pos);
  }

  //numElements++;

  if(numElements == maxSize){grow();}
}


template <typename T>
bool MyHeap<T>::empty()
{
  return numElements; 
}


template <typename T>
int MyHeap<T>::size() const
{
  return numElements;
}


template <typename T>
void MyHeap<T>::shrink()
{
  maxSize = maxSize * 3 / 4;

  T *newHeap = new T[maxSize];

  for(int i = 0;i < numElements;i++)
  {
    newHeap[i] = heap[i];
  }

  delete[] heap;
  heap = newHeap;
  newHeap = NULL;
}


template <typename T>
void MyHeap<T>::grow()
{
  maxSize = maxSize * 2;

  T *newHeap = new T[maxSize];

  for(int i = 0;i < numElements;i++)
  {
    newHeap[i] = heap[i];
  }

  delete[] heap;
  heap = newHeap;
  newHeap = NULL;
}

template <typename T>
bool MyHeap<T>::isLeaf(int i) const
{
  return (i >= numElements/2 && i < numElements);
}


template <typename T>
int MyHeap<T>::parent(int i) const
{
  return ((i - 1) / 2);
}
