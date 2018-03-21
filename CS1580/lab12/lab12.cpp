//Name: Evan Wilcox       Date: 11/8/17
//Class: CS1580           Section: E
//Filename: lab12.cpp
//Desc: test adding and subtracting two vectors

#include "vector.h"

int main()
{
  float x, y, z;
  
  cout << "Vectors!" << endl << endl;
  
  cout << "Enter a vector: ";
  cin >> x >> y >> z;
  vector v(x, y, z);
  
  cout << "Enter another vector: ";
  cin >> x >> y >> z;
  vector e(x, y, z);
  
  cout << "Sum of two vectors = " << (v + e) << endl;
  cout << "Diffrence of two vectors = " << (v - e) << endl;
  cout << "Bye!" << endl;
  
  return 0;
}
