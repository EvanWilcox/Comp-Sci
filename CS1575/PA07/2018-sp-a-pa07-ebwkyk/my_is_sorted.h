
#ifndef MY_IS_SORTED
#define MY_IS_SORTED

template <typename T>
bool my_is_sorted(T source[], int size)
{
  for(int i = 0;i < size;i++)
  {
    if(i * 2 < size)
    {
      if(source[i] < source[i*2] && source[i] < source[i*2+1])
      {
        return false;
      }
    }
  }

  return true;
}

#endif
