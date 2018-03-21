//Name: EVAN WILCOX       Date: 10/13/17
//Class: CS1570           Section: B
//File: walkSimulatorFunctions.cpp
//Desc: Function Implentation file for walkSimulator.cpp

#include "walkSimulator.h"


int rand_distance(const int rand_min, const int rand_max)
{
  return rand_min + (rand() % (rand_max - rand_min +1));
}

void move_random(int& x_pos, int& y_pos, const int distance,
  char& lastDirection, const int newDirection)
{
  const char NORTH = 'N';
  const char SOUTH = 'S';
  const char EAST = 'E';
  const char WEST = 'W';  


  if(newDirection == 0)
  {
    //Left turns
    switch(lastDirection)
    {
      case NORTH:
        x_pos -= distance;
        lastDirection = WEST;
        break;
      case SOUTH:
        x_pos += distance;
        lastDirection = EAST;
        break;
      case EAST:
        y_pos += distance;
        lastDirection = NORTH;
        break;
      case WEST:
        y_pos -= distance;
        lastDirection = SOUTH;
        break;
    }
  }
  else
  {
    //Right turns
    switch(lastDirection)
    {
      case NORTH:
        x_pos += distance;
        lastDirection = EAST;
        break;
      case SOUTH:
        x_pos -= distance;
        lastDirection = WEST;
        break;
      case EAST:
        y_pos -= distance;
        lastDirection = SOUTH;
        break;
      case WEST:
        y_pos += distance;
        lastDirection = NORTH;
        break;
    }

  }
  return;
}

void move_guided(int& x_pos, int& y_pos, const int distance,
  const int direction)
{
  const int Y_CORRECT_MAX = 40;
  const int X_CORRECT_MAX = 80;
  const int Y_INCORRECT_MAX = 90;
  const int X_INCORRECT_MAX = 100;

  
  if(direction <= Y_CORRECT_MAX)
  {
    if(y_pos > 0)
      y_pos -= distance;
    else
      y_pos += distance;
  }
  else if(direction > Y_CORRECT_MAX && direction <= X_CORRECT_MAX)
  {
    if(x_pos > 0)
      x_pos -= distance;
    else
      x_pos += distance;
  }
  else if(direction > X_CORRECT_MAX && direction <= Y_INCORRECT_MAX)
  {
    if(y_pos > 0)

      y_pos += distance;
    else
      y_pos -= distance;
  }
  else if(direction > Y_INCORRECT_MAX && direction <= X_INCORRECT_MAX)
  {
    if(x_pos > 0)

      x_pos += distance;

    else
      x_pos -= distance;
  }
  return;
}

void swap(int& x_pos, int& y_pos)
{
  x_pos ^= y_pos ^= x_pos ^= y_pos;
  return;
}

float distance_between(const int one_x, const int one_y, const int two_x,
  const int two_y)
{
  return sqrt(pow(one_x - two_x, 2)+pow(one_y - two_y, 2));
}

void jump_to_location(int& start_x, int& start_y, const int end_x,
  const int end_y)
{
  start_x = end_x;
  start_y = end_y;
  return;
}

void output(const int hansHome, const int hansLost, const int freeRide, const int jail)
{    
  cout << "Hans made it home with the penguin "
    << hansHome / static_cast<float>(NUM_SIMS) * 100 << "% of the time."
    << endl;
  cout << "Hans was got lost " << hansLost / static_cast<float>(NUM_SIMS)
    * 100 << "% of the time." << endl;
  cout << "Hans got a free ride home with his penguin from the cop " 
    << freeRide / static_cast<float>(NUM_SIMS) * 100 << "% of the time." 
    << endl;
  cout << "Hans went to jail " << jail / static_cast<float>(NUM_SIMS) * 100 
    << "% of the time." << endl;  

  return;
}

void print_pos(const int x_pos, const int y_pos, const char name)
{
  cout << name << ": (" << x_pos << ", " << y_pos << ")" << endl;
  return;
}
