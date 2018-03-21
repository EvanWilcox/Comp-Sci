//Name: Evan Wilcox         Date: 10/11/17
//Class: CS1580             Section: E
//Filename: circleMain.cpp
//Desc: Calculates the circumference, diameter, and area of a circle given
//      a radius

#include "circle.h"

int main()
{
  greeting();
  
  Circle circle;
  
  //sets radius of circle
  getRadius(circle.m_radius);       
  //sets area of circle
  circle.m_area = calculateArea(circle.m_radius); 
  //sets diameter of circle
  circle.m_diameter = calculateDiameter(circle.m_radius);
  //sets circumference of circle
  circle.m_circumference = calculateCircumference(circle.m_radius);
  //prints out details of circle
  printCircle(circle);

  int num1 = 5;
  int num2 = 7;

  char char1 = 'a';
  char char2 = 'b';

  swaper(num1, num2);     //swaps num1 and num2 using swap template
  swaper(char1, char2);   //swaps char1 and char3 using swap template

  cout << "The new value of num1 and num2 is " << num1 << " and " << num2
       << endl;       
  cout << "The new value of char1 and char2 is " << char1 << " and " << char2
       << endl;        
       
  cout << "Goodbye!" << endl;

  return 0;
}
