// Name: Evan Wilcox      Date: 11/15/17
// Class: CS1570          Section: B
// Filename: penguin_farmer.h
// Desc: Header file for penguin_farmer class.

#ifndef PENG_FRMR_H
#define PENG_FRMR_H

#include "penguin.h"

// Desc: The penguin_farmer() constructs a penguin farmer.
// Pre:  None.
// Post: A penguin farmer is constructed.

// Desc: The feed() simulates feeding a penguin.
// Pre:  None.
// Post: m_food is updated if a penguin was fed.

// Desc: The yell() yells if the penguin farmer was bitten.
// Pre:  None.
// Post: Bitten message is output to screen if bitten.

// Desc: The getTimesBitten() returns times penguin farmer has been bitten.
// Pre:  None.
// Post: m_timesBitten is returned.

// Desc: The operator <<() defines the insertion operator for penguin_farmer.
// Pre:  None.
// Post: Definition is output to os.


class penguin_farmer
{
  private:
    string m_name;            // Penguin farmer's name
    float m_food;             // Penguin farmer's food in lbs
    float m_money;            // Penguin farmer's money in $
    int m_timesBitten;        // Times penguin farmer has been bitten

  public:
    penguin_farmer(const string n, const float f, const float m):m_name(n),m_food(f),m_money(m), m_timesBitten(0){}
    
    bool feed(penguin& p);
    void yell(const bool fed);
    
    int getTimesBitten() const;
    
    friend ostream& operator <<(ostream& os, const penguin_farmer pf);
};

#endif
