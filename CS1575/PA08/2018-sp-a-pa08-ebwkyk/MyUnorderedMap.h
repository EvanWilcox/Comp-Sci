#ifndef MYUNORDEREDMAP_H
#define MYUNORDEREDMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Dictionary.h"

using std::cout;
using std::endl;

/*
   Writes to a string array containing: 
 * the your (the student author’s) Campus Username in lowercase (at index 0)
 * and Student ID# (at index 1).
 Takes as input a pre-existing length-2 string array.
 */
void get_identity(std::string my_id[]);


template <typename K, typename V>
class MyUnorderedMap: public Dictionary<K, V>
{
  private:
    MyPair<K, V> *m_data;
    
    int data_size;
    int reserved_size;
    
    // To make it easier on you (rather than use void pointers) we'll only test with std::string keys
    int hash(const K &key) const;

  public:
    // Should start data_size and reserved_size at 0, m_data to nullptr
    MyUnorderedMap();
    
    ~MyUnorderedMap();
    
    MyUnorderedMap(const MyUnorderedMap<K, V> &source);
    
    MyUnorderedMap<K, V> & operator=(const MyUnorderedMap<K, V> &source);
    
    V & at(const K &key);
    
    V & operator[](const K &key);
    
    bool empty() const;
    
    int size() const;
    
    // data_size and reserve size should be 0 after this.
    void clear();
    
    void insert(const MyPair<K, V> &init_pair);
    
    void erase(const K &key);
    
    MyPair<K, V> * find(const K &key) const;
    
    void print() const;
    
    int count(const K &key) const;
    
    // This one was not in the BST, but is in the HT
    // Grows or shrinks reserved_size and size of dynamic array to be new_cap large,
    // and nothing else.
    // Other functions, like insert, erase, or [], should decide how large to make the new cap
    // and call reserve themselves with that size.
    // Those other functions should choose to double the reserved size when the HT becomes 60% full,
    // and to shrink the HT when it becomes 10% full, to a resulting 30%.
    // Remember to re-hash!
    void reserve(int new_cap);

};

#include "MyUnorderedMap.hpp"

#endif

