//Name: EVAN WILCOX       Date: 10/13/17
//Class: CS1570           Section: B
//File: walkSimulator.cpp
//Desc: Simulates Hans trying to find his penguin and return home.

#include "walkSimulator.h"


int main()
{
  srand(2); 

  int hans_x;
  int hans_y;

  int cop_x;
  int cop_y;

  int penguin_x;
  int penguin_y;

  int newDirection;
  int distance;

  int numDecP;
  int copCounter;

  char hansLastDirection;
  char penguinLastDirection;

  bool decPLessThanMax;

  bool hansCaughtPenguin;
  bool copCaughtHans;
  bool copCaughtPenguin;
  bool foundHome;

  int countHansHome = 0;
  int countFreeRide = 0;
  int countHansLost = 0;
  int countJail = 0;


  for(int i = 0;i < NUM_SIMS;i+=1)
  {
    //resetting variables for each simulation

    hans_x = 0; 
    hans_y = rand_distance(HANS_MIN, HANS_MAX);

    hansLastDirection = 'N';

    penguin_x = 200 + (-1 * rand_distance(PENGUIN_MIN, PENGUIN_MAX));
    penguin_y = 200;

    penguinLastDirection = 'W';

    cop_x = 75;
    cop_y = 0;

    distance = 0;

    numDecP = 1; 

    copCounter = 1;

    hansCaughtPenguin = false;
    copCaughtHans = false;
    copCaughtPenguin = false;

    foundHome = false;


    //trying to find penguin
    do
    {
      //move hans
      newDirection = rand() % 2;
      distance = rand_distance(HANS_MIN, HANS_MAX);
      move_random(hans_x, hans_y, distance, hansLastDirection, newDirection);

      //move penguin
      newDirection = rand() % 2;
      distance = rand_distance(PENGUIN_MIN, PENGUIN_MAX);
      move_random(penguin_x, penguin_y, distance, penguinLastDirection,
          newDirection);

      //move cop if he hasn't caught the penguin
      if(!copCaughtPenguin)
      {
        if(copCounter % COP_TURN_MAX == 0)
        {
          swap(cop_x, cop_y);
        }
        else if(copCounter % COP_TURN_MAX + 1 == 0)
        {
          swap(cop_x, cop_y);
          copCounter = 0;
        }
      }

      //check distances
      if(distance_between(hans_x, hans_y, penguin_x, penguin_y) 
        <= PENGUIN_RADIUS)
      {
        hansCaughtPenguin = true;
        jump_to_location(hans_x, hans_y, penguin_x, penguin_y);
      }
      else if(distance_between(hans_x, hans_y, cop_x, cop_y) <= COP_RADIUS)
      {
        copCaughtHans = true;
      }
      else if(distance_between(cop_x, cop_y, penguin_x, penguin_y)
          <= PENGUIN_RADIUS)
      {
        copCaughtPenguin = true;
        jump_to_location(cop_x, cop_y, penguin_x, penguin_y);
      }

      decPLessThanMax = numDecP < MAX_DEC_P;

      //increment
      numDecP++;
      copCounter++;

    } while(decPLessThanMax && !hansCaughtPenguin && !copCaughtHans);

    //returning home if found penguin and hans not caught by cop
    while(decPLessThanMax && !foundHome && !copCaughtHans && hansCaughtPenguin)
    {
      //moves hans
      newDirection = (rand() % 100) + 1;
      distance = rand_distance(HANS_MIN, HANS_MAX);
      move_guided(hans_x, hans_y, distance, newDirection);

      //moves penguin to hans
      jump_to_location(penguin_x, penguin_y, hans_x, hans_y);

      //moves cop      
      if(copCounter % COP_TURN_MAX == 0)
      {
        swap(cop_x, cop_y);
      }
      else if(copCounter % COP_TURN_MAX + 1 == 0)
      {
        swap(cop_x, cop_y);
        copCounter = 0;
      }

      //check distances
      if(distance_between(hans_x, hans_y, HOME_X, HOME_Y) <= HOME_RADIUS) 
      {          
        foundHome = true;
      }
      else if(distance_between(hans_x, hans_y, cop_x, cop_y) <= COP_RADIUS)
      {     
        copCaughtHans = true;
        hansCaughtPenguin = true;
      }

      decPLessThanMax = numDecP < MAX_DEC_P;

      //increment
      numDecP++;
    };

    //increment hault conditions
    if(!decPLessThanMax)
    {
      countHansLost++;
    }
    else if(foundHome)
    {
      countHansHome++;
    }
    else if(copCaughtHans && (hansCaughtPenguin || copCaughtPenguin))
    {
      countFreeRide++;
    }
    else if(copCaughtHans)
    {
      countJail++;
    }
  }

  //output
  output(countHansHome, countHansLost, countFreeRide, countJail);

  return 0;
}

