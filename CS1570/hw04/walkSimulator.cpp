// Name: WILCOX, EVAN     Date: 9/15/17
// Class: CS1570          Section: B
// File: walkSimulator.cpp
// Description: Simulates Hans walking to Nick's office 200 times.

#include <iostream> 
#include <cmath>
using namespace std;


// (0,0)         home
// (1000, 1000)  nick's office


int main()
{
  const int NUM_SIMS = 200;     // total num of simulations
  const int INITIAL_DIS = 20;   // fist distance walked on first walk
  const int MAX_DEC_P = 500;    // max number of decison points
  const int OFFICE_RADIUS = 50; // minimum range for hans to see the office
  const int HOME_RADIUS = 30;   // mimimum range for hans to see his house

  int xPosition;                // hans x position
  int yPosition;                // hans y position

  int totalDisTravelled;        // total distance travelled
  int disTravelled;             // distance travelled since last decision point

  float disFromHome;            // distance from home
  float disFromOffice;          // distance from office

  char lastDirectionOfTravell;  // direction of last travell (N, S, E, W)

  int numOfDecP;                // current num of decison points

  bool DecPLessThanMax;         // true if numOfDecP is less than MAX_DEC_P
  bool closeToHome;             // true if close to home and numDecP > 5
  bool closeToOffice;           // true if close to office


  //Output Header
  cout << "Location | Distance Travelled (ft)" << endl;
  cout << "======== | =======================" << endl;


  //Simulations
  for(int i = 0;i < NUM_SIMS; i+=1) // runs simulations 0-NUM_SIMS
  {                            
    
    //Reseting variables for each simulation    
    
    totalDisTravelled = 0;
    disTravelled = INITIAL_DIS + i;

    lastDirectionOfTravell = 'N';

    xPosition = 0;
    yPosition = disTravelled;

    numOfDecP = 1;


    do
    {


      disTravelled = ((static_cast<int>(disTravelled * 214013 + 2531011)
                     % 2147483647) % 200 ) + 100;
      
      totalDisTravelled += disTravelled;


      if(numOfDecP % 7 == 0)  
      {
        //Left turns
        switch(lastDirectionOfTravell)
        {
          case 'N':
            xPosition -= disTravelled;
            lastDirectionOfTravell = 'W';
            break;
          case 'S':
            xPosition += disTravelled;
            lastDirectionOfTravell = 'E';
            break;
          case 'E':
            yPosition += disTravelled;
            lastDirectionOfTravell = 'N';
            break;
          case 'W':
            yPosition -= disTravelled;
            lastDirectionOfTravell = 'S';
            break;
        }
      }
      else          
      {
        //Right turns
        switch(lastDirectionOfTravell)
        {
          case 'N':
            xPosition += disTravelled;
            lastDirectionOfTravell = 'E';
            break;
          case 'S':
            xPosition -= disTravelled;
            lastDirectionOfTravell = 'W';
            break;
          case 'E':
            yPosition -= disTravelled;
            lastDirectionOfTravell = 'S';
            break;
          case 'W':
            yPosition += disTravelled;
            lastDirectionOfTravell = 'N';
            break;
        }

      }


      disFromHome = sqrt(pow(xPosition, 2) + pow(yPosition, 2));
      disFromOffice = sqrt(pow(xPosition-1000, 2) + pow(yPosition-1000, 2));

      DecPLessThanMax = numOfDecP < MAX_DEC_P;
      closeToHome = disFromHome <= HOME_RADIUS && numOfDecP > 5;
      closeToOffice = disFromOffice <= OFFICE_RADIUS;

      numOfDecP++; 

    }while(DecPLessThanMax && !closeToHome && !closeToOffice);


    //Output location
    if(closeToHome)
    {
      cout << "Home     | ";
    }
    else if(closeToOffice)
    {
      cout << "Office   | ";
    }
    else
    {
      cout << "Lost     | ";
    }


    //Output distance
    if(totalDisTravelled >= 5280)
    {
      cout << totalDisTravelled << "(~" << totalDisTravelled/5280.0
        << " Miles)" << endl;
    }
    else
    {
      cout << totalDisTravelled << endl;
    }
  }

  return 0;

}
