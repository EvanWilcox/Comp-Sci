//Name: Evan Wilcox       Date: 11/8/17
//Class: CS1580           Section: E
//Filename: vector.h
//Desc: header file for vector.cpp

#include <iostream>
using namespace std;

class vector
{
  private:
    float m_x;
    float m_y;
    float m_z;

  public: 
    vector(const float x, const float y, const float z):m_x(x),m_y(y),m_z(z){};
    vector operator +(const vector rhs) const;
    vector operator -(const vector rhs) const;
    friend ostream& operator <<(ostream& os, const vector v);
    
    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(const float x);
    void setY(const float y);
    void setZ(const float z);
};
