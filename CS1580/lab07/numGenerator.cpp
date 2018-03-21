//Name: EVAN WILCOX       Date: 10/4/17
//Class: CS1580           Section: E
//File: numGenerator.cpp
//Desc: Generates a random number between user choosen bounds.

#include <iostream>
#include <cstdlib>
using namespace std;

//Desc: Prints greeting to screen
//Pre:  None
//Post: Greeting is printed to screen
void greeting();

//Desc: Prompts user for choice and returns char
//Pre:  None
//Post: Prompti printed to screen and choice is returned
char prompt();

//Desc: Gets 2 positive nums from user
//Pre:  None
//Post: num1 and num2 refrence vales are changed
void get2Nums(int& num1, int& num2);

//Desc: Gets 2 positive nums from user
//Pre:  None
//Post: num1 and num2 refrence vales are changed
void get2Nums(float& num1, float& num2);

//Desc: Swaps the values of num1 and num2
//Pre:  None
//Post: values of num1 and num2 are swapped
void swap(int& num1, int& num2);

//Desc: Swaps the values of num1 and num2
//Pre:  None
//Post: values of num1 and num2 are swapped
void swap(float& num1, float& num2);

//Desc: Generates random int betwen upper and lower
//Pre:  lower and upper must be positive
//Post: Returns random int between upper and lower
int randNumGen(const int lower, const int upper);

//Desc: Generates random float between upper and lower
//Pre:  lower and upper must be positive
//Post: returns random float between upper and lower
float randNumGen(const float lower, const float upper);


int main()
{
  srand(time(NULL));
  
  char choice;

  int iOne;
  int iTwo;

  float fOne;
  float fTwo;

  greeting();

  do
  {
    if(prompt() == 'f')
    {
      get2Nums(fOne, fTwo);
      cout << "The random number is " << randNumGen(fOne, fTwo) << endl;
    }
    else
    {
      get2Nums(iOne, iTwo);
      cout << "The random number is " << randNumGen(iOne, iTwo) << endl;
    }

    cout << endl << "Do you need more random numbers?(y/n): ";
    cin >> choice;

  } while(choice == 'y');

  cout << endl << "Goodbye!" << endl;

  return 0;
}

void greeting()
{
  cout << "Welcome to the Random Number Generator App!" << endl << endl;
}

char prompt()
{
  char input;

  do
  {
    cout << "Do you need an random integer or float?(i/f): ";
    cin >> input;
  } while(!(input == 'i' || input  == 'f'));
    return input;
}

void get2Nums(int& num1, int& num2)
{
  do
  {
    cout << "Enter a positive int 1: ";
    cin >> num1;
  } while(num1 < 0);

  do
  {
    cout << "Enter a positive int 2: ";
    cin >> num2;
  } while(num2 < 0);
  
  if(num1 > num2)
    swap(num1, num2);
  
  
  return;
}

void get2Nums(float& num1, float& num2)
{
  do
  {
    cout << "Enter a positive float 1: ";
    cin >> num1;
  } while(num1 < 0);

  do
  {
    cout << "Enter a positive float 2: ";
    cin >> num2;
  } while(num2 < 0);
  
  if(num1 > num2)
    swap(num1, num2);
  
  return;
}

void swap(int& num1, int& num2)
{
  num1 ^= num2 ^= num1 ^= num2;
}

void swap(float& num1, float& num2)
{
  float temp = num1;
  num1 = num2;
  num2 = temp;
}

int randNumGen(const int lower, const int upper)
{
  int num;
  do
  {
    num = rand() % upper + 1;
  } while(num < lower || num > upper);
  return num;
}

float randNumGen(const float lower, const float upper)
{
  float num;
  float temp = static_cast<float>(rand())/RAND_MAX;
  num = lower + (temp * (upper - lower));
  return num;
}

