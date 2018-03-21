// Name: Evan Wilcox	Date: 9/1/2017
// Section: b
// FIle: lensCalculator.cpp
// Description: Calculates thickness of lens after inputting required variables.

#include<iostream>
using namespace std;

int main()
{
  //Variables
  const float NICK = 4.2;	//nick needs money constant
  const int REFRACTION_INDEX = 2;	//refraction index constant
  int thickness;
  int leftAcuity;
  int rightAcuity;
  int socialNum;		//last 4 digits of social security number
  int insAudFac = 0;		//insurance audjustment factor
  bool hasInsurance;	
  
  //Input
  cout << "Welcome to the lens thickness calculator." << endl << endl;
  cout << "Please Enter: " << endl << endl;
  cout << "  Left Acuity: ";
  cin >> leftAcuity;
  cout << "  Right Acuity: ";
  cin >> rightAcuity;
  cout << "  Last four dgits of SSN: ";
  cin >> socialNum;
  cout << "  Incurance: ";
  cin >> hasInsurance;
  
  //Calculations
  insAudFac = (socialNum / 10) % 10;
  thickness = (3 + static_cast<float>(leftAcuity) /
    (rightAcuity + REFRACTION_INDEX)) * NICK + (insAudFac * hasInsurance);
  
  //Output
  cout << endl << "Thickness: " << thickness << endl << endl;
  cout << "Have a nice day!" << endl;

  return 0;
}
