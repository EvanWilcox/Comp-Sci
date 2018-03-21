//Name: Evan Wilcox       Date: 10/11/17
//Class: CS1580           Section: E
//Filename: circle.h
//Desc: 

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;

struct Circle
{
  int m_radius;
  float m_diameter;
  float m_circumference;
  float m_area;
};

//Desc: Prints greeting to screen
//Pre:  None
//Post: Greeting is printed to screen
void greeting();

//Desc: Gets radius from user
//Pre:  None
//Post: refrence variable radius is changed to user input
void getRadius(int &radius);

//Desc: Calculates area of a circle given an radius
//Pre:  radius must be positive
//Post: diameter is returned
float calculateArea(const int radius);

//Desc: Calulates diameter of a circle given a radius
//Pre:  radius must be positive
//Post: diameter is returned
float calculateDiameter(const int radius);

//Desc: Calculates circumference of a circle given a radius
//Pre:  radius must be positive
//Post: circumference is returned
float calculateCircumference(const int radius);

//Desc: Prints  details of a circle
//Pre:  None
//Post: details of circle is printed to screen
void printCircle(const Circle circle);

//Desc: Swaps values of two variabled of same type
//Pre:  None
//Post: variables values are swapped
template<typename T>
void swaper(T &value1, T &value2)
{
  T temp = value1;
  value1 = value2;
  value2 = temp;
  return;
}

#endif
