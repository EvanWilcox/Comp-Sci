// Name: Evan WIlcox          DateL 9/20/17
// Class: CS1580              Sectioin: e
// File: shoneys.cpp         
// Description: Calculates total of purchase

#include <iostream>
using namespace std;

int main()
{
  float total = 0;      //total of purchase

  char choice;          //user input

  const float CHICKEN_PRICE = 4.45;     //price of chicken sandwich
  const float FRIES_PRICE = 0.9;        //price of curly fries
  const float SAUCE_PRICE = 0.99;       //price of nugget sauce
  const float SODA_PRICE = 2.15;        //price of soda
  const float SHONEY_PRICE = 6.99;      //price of big shoney
  const float NACHOS_PRICE = 5.99;      //price of nachos
  const float COFFEE_PRICE = 2.29;      //price of coffee

  //Menu output
  cout << "Welcome to the Big Kahuna POS!" << endl << endl;
  cout << "Menu Choices: " << endl;
  cout << "a) Chicken Sandwich ($" << CHICKEN_PRICE <<" )" << endl;
  cout << "b) Curly Fries ($" << FRIES_PRICE << ")" << endl;
  cout << "c) Szechuan Chicken McNugget Sauce ($" << SAUCE_PRICE << ")"<<endl;
  cout << "d) Soda ($" << SODA_PRICE << ")" << endl;
  cout << "e) Big Shoney ($" << SHONEY_PRICE << ")" << endl;
  cout << "f) Bucket o' Nachoos ($" << NACHOS_PRICE << ")" << endl;
  cout << "g) Coffee ($" << COFFEE_PRICE << ")" << endl;
  cout << "Order 3 items." << endl << endl;

  for(int i = 0;i <3;i+=1)
  {  
    cout << "What does the customer want: ";
    cin >> choice;
    switch(choice)
    {
      case 'a':
        total += CHICKEN_PRICE;
        break;
      case 'b':
        total += FRIES_PRICE;
        break;
      case 'c':
        total += SAUCE_PRICE;
        break;
      case 'd':
        total += SODA_PRICE;
        break;
      case 'e':
        total += SHONEY_PRICE;
        break;
      case 'f':
        total += NACHOS_PRICE;
        break;
      case 'g':
        total += COFFEE_PRICE;
        break;
      default:
        cout << "Invalid Input." << endl;
        i-=1;
    }
  }
  //Output and goodbye
  cout << "The total is $" << total << "\n\nThank you, come again!" << endl;

  return 0;
}
