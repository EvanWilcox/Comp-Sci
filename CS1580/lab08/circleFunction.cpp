//Name: Evan Wilcox         Date: 10/11/17
//Class: CS1580             Section: E
//Filename: circleFunction.cpp
//Desc: Function definitons for circleMain.cpp and circle.h

#include "circle.h"

void greeting()
{
  cout << "Hello, Welcome to the world of circles." << endl;
  return;
}

void getRadius(int &radius)
{
  do
  {
    cout << "What is the radius?: ";
    cin >> radius;
  } while(radius <= 0);
  return;
}

float calculateArea(const int radius)
{
  const float PI = 3.14159;
  return PI * radius * radius;
}

float calculateDiameter(const int radius)
{
  return radius * 2;
}

float calculateCircumference(const int radius)
{
  const float PI = 3.14159;
  return 2 * PI * radius;
}

void printCircle(const Circle circle)
{  
  cout << "The area of the circle is: " << circle.m_area << endl;
  cout << "The circumference of the circle is: " << circle.m_circumference << endl;
  cout << "The diameter of the circle is: " << circle.m_diameter << endl;
  return;
}
