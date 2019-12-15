


void get_identity(std::string my_id[])
{
  my_id[0] = "ebwkyk";
  my_id[1] = "12540849";
}


template <typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap()
{
  data_size = 0;
  reserved_size = 0;
  m_data = NULL;
}


template <typename K, typename V>
MyUnorderedMap<K, V>::~MyUnorderedMap()
{
  clear();
}


template <typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap(const MyUnorderedMap<K, V> &source)
{
  data_size = source.data_size;
  reserved_size = source.reserved_size;
  
  m_data = new MyPair<K, V>[reserved_size];
  
  MyPair<K, V> temp;
  
  for(int i = 0;i < reserved_size;i++)
  {
    m_data[i].first = source.m_data[i].first;
    m_data[i].second = source.m_data[i].second;
  }
}


template <typename K, typename V>
MyUnorderedMap<K, V> & MyUnorderedMap<K, V>::operator=(const MyUnorderedMap<K, V> &source)
{
  clear();

  data_size = source.data_size;
  reserved_size = source.reserved_size;
  m_data = new MyPair<K, V>[reserved_size];
  
  for(int i = 0;i < reserved_size;i++)
  {
    m_data[i].first = source.m_data[i].first;
    m_data[i].second = source.m_data[i].second;
  }

  return *this;
}


template <typename K, typename V>
V & MyUnorderedMap<K, V>::at(const K &key)
{
  if(find(key) == NULL)
  {
    throw std::out_of_range("Key not found");
  }
  else
  {
    return find(key)->second;
  }
}


template <typename K, typename V>
V & MyUnorderedMap<K, V>::operator[](const K &key)
{
  if(m_data == NULL)
  {
    reserved_size = 10;
    m_data = new MyPair<K, V>[reserved_size];
    
    for(int i = 0;i < reserved_size;i++)
    {
      m_data[i].first = "EMPTY";
    }
  }
  
  if(find(key) == NULL)
  {
    int home;
    int pos = home = hash(key);

    for(int i = 1; m_data[pos].first != "EMPTY" && m_data[pos].first != "TOMB";i++)
    {
      pos = (home + i) % reserved_size;
    }

    m_data[pos].first = key;
    data_size++;

    if(data_size <= reserved_size * 6 / 10)
    {
      reserve(reserved_size * 2);
    }


    return m_data[pos].second;
  }
  else
  {
    return find(key)->second;
  }
}


template <typename K, typename V>
bool MyUnorderedMap<K, V>::empty() const
{
  return !data_size;
}


template <typename K, typename V>
int MyUnorderedMap<K, V>::size() const
{
  return data_size;
}


template <typename K, typename V>
void MyUnorderedMap<K, V>::clear()
{
  if(m_data != NULL)
  {
    delete[] m_data;
    data_size = 0;
    reserved_size = 0;
  }
}


template <typename K, typename V>
void MyUnorderedMap<K, V>::insert(const MyPair<K, V> &init_pair)
{
  
  if(m_data == NULL)
  {
    reserved_size = 10;
    m_data = new MyPair<K, V>[reserved_size];
    
    for(int i = 0;i < reserved_size;i++)
    {
      m_data[i].first = "EMPTY";
    }
  }


  int home;
  int pos = home = hash(init_pair.first);

  for(int i = 1; m_data[pos].first != "EMPTY" && m_data[pos].first != "TOMB";i++)
  {
    pos = (home + i) % reserved_size;
  }

  m_data[pos] = init_pair;

  data_size++;

  if(data_size >= reserved_size * 6 / 10)
  {
    reserve(reserved_size * 2);
  }
}


template <typename K, typename V>
void MyUnorderedMap<K, V>::erase(const K &key)
{
  int home;
  int pos = home = hash(key);

  for(int i = 1;m_data[pos].first != key;i++)
  {
    pos = (home + i) % reserved_size;
  }
  
  MyPair<K, V> tomb("TOMB");
  m_data[pos] = tomb;

  data_size--;

  if(data_size <= reserved_size / 10)
  {
    reserve(reserved_size * 10 / 3);
  }
}


template <typename K, typename V>
MyPair<K, V> * MyUnorderedMap<K, V>::find(const K &key) const
{
  if(m_data != NULL)
  {
    int home;
    int pos = home = hash(key);
    int count = 0;
    
    for(int i = 1;m_data[pos].first != key;i++)
    {
      pos = (home + i) % reserved_size;
      
      count++;
      if(count >= reserved_size)
      {
        return NULL;
      }
    }
    
    return &m_data[pos];
  }
  else
  {
    return NULL;
  }
}


template <typename K, typename V>
void MyUnorderedMap<K, V>::print() const
{
  if(m_data != NULL)
  {
    cout << "[";
    
    int i;
    int j;
    
    for(i = 0, j = 0;i < reserved_size;i++)
    {
      if(m_data[i].first != "EMPTY" && m_data[i].first != "TOMB")
      {
        cout << "(" << m_data[i].first << ": " << m_data[i].second << ")";
        
        if(j < data_size-1)
        {
          cout << ", ";
        }
        
        j++;
      }
    }
    
    cout << "]";
  }
  else
  {
    cout << "[]";
  }
}


template <typename K, typename V>
int MyUnorderedMap<K, V>::count(const K &key) const
{
  if(find(key) == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


template <typename K, typename V>
void MyUnorderedMap<K, V>::reserve(int new_cap)
{
  MyPair<K, V> *tempArray = m_data;
  m_data = new MyPair<K, V>[new_cap];

  MyPair<K, V> temp("EMPTY");
  for(int i = 0;i < new_cap;i++)
  {
    m_data[i] = temp;
  }

  int oldSize = reserved_size;
  reserved_size = new_cap;

  for(int i = 0;i < oldSize;i++)
  {
    if(tempArray[i].first != "EMPTY" && tempArray[i].first != "TOMB")
    {
      insert(tempArray[i]);
    }
  }

  delete[] tempArray; 
}


template <typename K, typename V>
int MyUnorderedMap<K, V>::hash(const K &key) const
{
  int sum = 0;

  for(int i = 0;i < key.length();i++)
  {
    sum += key[i];
  }

  return sum % reserved_size;
}




