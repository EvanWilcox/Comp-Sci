// Name: Evan Wilcox      Date: 11/15/17
// Class: CS1570          Section: B
// Filename: penguin.h
// Desc: Header file for penguin class.

#ifndef PENG_H
#define PENG_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "math.h"
using namespace std;

// Desc: The poop() calculates the penguin's bowel movement.
// Pre:  None.
// Post: Returns the penguin's last bowel movement.

// Desc: The penguin() constructs a penguin.
// Pre:  None.
// Post: A penguin is constructed.

// Desc: The setName() sets the penguin's name.
// Pre:  None.
// Post: Sets the penguin's name to the given parameter or is given a random 
//       name if no parameter.

// Desc: The setWeight() sets the penguin's weight.
// Pre:  None.
// Post: The penguin's weight is set to the given parameter.

// Desc: The setAge() sets the penguin's age to the given parameter.
// Pre:  None.
// Post: The penguin's age is set to the given parameter.

// Desc: The getPoop() returns the penguin's last bowel movement.
// Pre:  None.
// Post: m_poop is returned.

// Desc: The eat() simulates the penguin eating.
// Pre:  None.
// Post: m_weight and m_age are updated and m_poop is set to poop().

// Desc: The operator <<() defines the insertion operator for penguin.
// Pre:  None.
// Post: Definition is output to os.


const int DEFAULT_AGE = 0;        // Default value for age
const float DEFAULT_WEIGHT = 5;   // Default value for weight

class penguin
{
  private:
    string m_name;                // Penguin's name
    float m_weight;               // Penguin's weight in lbs
    int m_age;                    // Penguin's age in days
    float m_poop;                 // Penguin's last bowel movement in lbs
    
    float poop(const float f);
  
  public:
    penguin():m_weight(DEFAULT_WEIGHT),m_age(DEFAULT_AGE){setName();}
    penguin(const string n, const float w, const int a);
    
    void setName();
    void setName(const string n);
    void setWeight(const float w);
    void setAge(const int a);
    
    float getPoop() const;
    
    bool eat(const float f);
    
    friend ostream& operator <<(ostream& os, const penguin p);
};

#endif
