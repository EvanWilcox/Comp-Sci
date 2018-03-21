// Name: EVAN WILCOX        Date: 10/03/17
// Class: CS1570            Section: B
// File: healthMenu.cpp   
// Description: A helth management menu for Hans

#include <iostream>
#include <cstdlib>
using namespace std;

//Function Prototypes

//Desc: The greeting() prints greeting to the screen
//Pre:  None
//Post: Greeting printed to screen
void greeting();

//Desc: The inputMenu() displays menu to user and prompts for choice
//Pre:  None
//Post: Menu is printed to screen and user choice is returned
int inputMenu();

//Desc: The getNumOfLegs() prompts, cleans, and returns  num of legs of the walk
//Pre:  None
//Post: The prompt is printed to the screen and num of legs is returned
int getNumOfLegs();

//Desc: The walk() prints the walk plan and calculaes totalDistanceWalked
//Pre:  legs must be a positive int
//Post: The walk plan is printed to screen and totalDistanceWalked is returned
int walk(const int legs);

//Desc: The getAnxietyLevel() prompts for and returns the anxiety level
//Pre:  None
//Post: Returns anxiety level
int getAnxietyLevel();

//Desc: The getDayOfWeek() prompts for and returns day of week (1-7)
//Pre:  None
//Post: Returns day of week 1-7
int getDayOfWeek();

//Desc: The getNumOfPills() calculates and returns num of pills
//Pre:  anxietyLevel must be between 1 and 10 and day must be between 1 and 7
//Post: Number of pills is returned
int getNumOfPills(const int anxietyLevel, const int day);

//Desc: The printPills() prints how many pills yoy should take to the screen
//Pre:  None
//Post: Number of pills is printed to screen
void printPills(const int numOfPills);

//Desc: The getHoursSlept() prompts for and returns hours slept
//Pre:  None
//Post: Hours slept is retunred
int getHoursSlept();

//Desc: The getNapTime() calculates and returns nap length
//Pre:  None
//Post: Returns nap length
int getNapTime(const int hoursSlept, const int distanceWalked,
  const int numOfPills);

//Desc: The printMinutes() prints how long you should nap
//Pre:  None
//Post: How long you should nap is printed to the screen
void printMinutes(const int num);

//Desc: The getWeigth() prompts for and returns weight
//Pre:  None
//Post: Returns weight
int getWeight();

//Desc: The getHeight() prompts for and returns height
//Pre:  None
//Post: Returns height
int getHeight();

//Desc: The getRoomTemp() prompts for and returns the room tempature
//Pre:  None
//Post: Returns room tempature
float getRoomTemp();

//Desc: The getCalories() calculates and returns daily calories
//Pre:  All parameters must be positive
//Post: Returns calories
int getCalories(const int weight, const int height, const float roomTemp,
  const int distance);

//Desc: The printCalories() prints the amount of calories
//Pre:  None
//Post: Prints the amount of calories to the screen
void printCalories(const int calories);



int main()
{
  srand(time(NULL));
  
  int choice;

  bool oneComplete = false;
  bool twoComplete = false;
  bool threeComplete = false;

  int distanceWalked;
  int numOfPills;

  greeting();

  do 
  {
    choice = inputMenu();
    switch(choice)
    {
      case 1:
        distanceWalked = walk(getNumOfLegs());
        oneComplete = true;
        break;

      case 2:
        numOfPills = getNumOfPills(getAnxietyLevel(), getDayOfWeek());
        printPills(numOfPills);
        twoComplete = true;
        break;

      case 3: 
        if(oneComplete && twoComplete)
        {
          printMinutes(getNapTime(getHoursSlept(), distanceWalked, numOfPills));
          threeComplete = true;
        }
        else
        {
          cout << endl << "!!Must complete steps 1 and 2 first!!" << endl;
        }        
        break;

      case 4:
        if(threeComplete)
        {
          printCalories(getCalories(getWeight(), getHeight(), getRoomTemp(),
            distanceWalked));
        }
        else
        {
          cout << endl << "!!Must complete step 3 first!!" << endl;
        }
        break;
    }
  } while(choice != 5);

  cout << endl << "Goodbye!" << endl;

  return 0;
}

//Function Definitions

void greeting()
{
  cout << "Greeting!" << endl;
  return;
}

int inputMenu()
{
  int choice;

  cout << endl << "Health-o-Matic Options: " << endl << endl;
  cout << "  1. Taking a Walk!" << endl;
  cout << "  2. Your Medications." << endl;
  cout << "  3. Nap Time!!" << endl;
  cout << "  4. Caloric Intake." << endl;
  cout << "  5. Quit." << endl << endl;
  cout << "Choice: ";
  cin >> choice;
  return choice;
}

int getNumOfLegs()
{
  int legs;
  do
  {
    cout << "How many legs of the walk will there be?: ";
    cin >> legs; 
  } while(!(legs > 0));
  return legs;
}

int walk(const int legs)
{
  int distanceWalked = 0;
  int steps;
  char direction;

  const int MAX_RAND = 120;
  const int MIN_RAND = 20;

  for(int i = 1;i <= legs;i+=1)
  {
    steps = MIN_RAND + (rand() % (MAX_RAND - MIN_RAND + 1 )); 
    distanceWalked += steps;
    direction = (i % 2)?'R':'L';
    cout << endl << i << ". " << steps << " steps, " << direction << endl;
    cout << endl << "Total Distance: " << distanceWalked << endl;
  }
  return distanceWalked;
}

int getAnxietyLevel()
{
  int anxietyLevel;
  do
  {
    cout << endl << "What is your anxiety level(1-10): ";
    cin >> anxietyLevel;
  } while(!(anxietyLevel < 11 && anxietyLevel > 0));
  return anxietyLevel;
}

int getDayOfWeek()
{
  int day;

  do
  {
    cout << endl << "What is the of the week(1-7): ";
    cin >> day;
  } while(!(day < 8 && day > 0));
  return day;
}

int getNumOfPills(int anxietyLevel, int day)
{
  int numOfPills = anxietyLevel - day;

  if(numOfPills < 0)
    numOfPills = 0;

  return numOfPills;
}

void printPills(const int numOfPills)
{
  cout << endl << "You should take " << numOfPills << " pills." << endl;
  return;
}

int getHoursSlept()
{
  int hours;
  do
  {
    cout << endl << "How many hours did you sleep last night?: ";
    cin >> hours;
  } while(!(hours > 0 && hours < 24));
  return hours;
}

int getNapTime(int hoursSlept, int distanceWalked, int numOfPills)
{
  int minutes;

  if(numOfPills > 0)
    minutes = (hoursSlept + distanceWalked) / numOfPills;
  else
    minutes = hoursSlept + distanceWalked;

  return minutes;
}

void printMinutes(int minutes)
{
  cout << endl << "You should nap for " << minutes << " minutes." << endl;
  return;
}

int getWeight()
{
  int weight;
  const int MAX_WEIGHT = 800;
  do
  {
    cout << "What is your weight?: ";
    cin >> weight; 
  } while(!(weight > 0 && weight < MAX_WEIGHT));
  return weight;
}

int getHeight()
{
  int height;
  const int MAX_HEIGHT = 84;
  
  do
  { 
    cout << "What is your height?: ";
    cin >> height;
  } while(!(height > 0 && height < MAX_HEIGHT));
  return height;
}

float getRoomTemp()
{ 
  float roomTemp;
  do
  {
    cout << endl << "What is the room temp?: ";
    cin >> roomTemp;
  } while(!(roomTemp >= 0));
  return roomTemp;
}

int getCalories(const int weight, const int height, const float roomTemp,
  const int distance)
{
  int calories = ((6 * weight) + (2 * height) + 1/roomTemp) + distance;
  return calories;
}

void printCalories(const int calories)
{
  cout << endl << "You require " << calories << " calories." << endl;
  return;
}
