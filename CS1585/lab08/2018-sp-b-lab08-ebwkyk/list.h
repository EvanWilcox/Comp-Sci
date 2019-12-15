#ifndef LIST_H
#define LIST_H

#include<stdexcept>
using namespace std;

/* Linked list element container */
template<class T>
struct Cell
{
  T elem;
  Cell* next;

  Cell(const T& e, Cell* n); // Sets element and next pointer directly; no copying done
  Cell(const Cell& c); // Performs a deep copy

  // No destructor for a reason! The List class deallocates memory as needed.
};


/* Linked List */
template<class T>
class List
{
  public:
    // Constructor
    List(); // Makes a new empty list

    // Copy Constructor
    List(const List& l); // Performs a deep copy

    // Destructor
    ~List();

    // Inserting stuff
    void prepend(const T& t); // Adds element to the front of the list
    void append(const T& t); // Adds element to the back of the list

    // Removing stuff
    void pop(); // Removes the head element

    // Accessors
    T& head(); // Returns a reference to the first element of the list
    List tail(); // Returns a copy of everything except the first element

    Cell<T>* iterator(); // Returns a pointer to the head cell or NULL if the list is empty

    // Properties
    unsigned int length() const; // Returns number of elements in list
    bool empty() const; // Returns true if the list is empty; false otherwise

  private:
    Cell<T>* cell;
};

#include"list.hpp"
#endif
