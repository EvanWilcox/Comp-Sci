// Name: EVAN WILCOX        Date: 9/14/17
// Class: cs1570            Section: b
// File name: stomachFlowchart.cpp
// Description: Flow chart to diagnose stomach problems.

#include <iostream>
#include <string>
using namespace std;

int main()
{
  char input;       // user input
  string name;      // patient name

  do
  {  
    cout << endl << "Welcom to the Stomach Problem Flow Chart" << endl;
    cout << "Patienst's name: ";
    cin >> name;

    do
    {
      cout << endl << "Stress related?";
      cout << endl << "(y/n): ";
      cin >> input;
    }while(!(input == 'y' || input == 'n' ));

    if(input == 'y')
    {
      do
      {
        cout << endl << "Diarrhea, mad dash?";
        cout << endl << "(y/n): ";
        cin >> input;
      }while(!(input == 'y' || input == 'n' ));

      if(input == 'y')
      {
        cout << "Diarrhea and sudden fecal urge are common"
          << " panic symptoms, and can self fulfill";
      }
      else
      {
        do
        {
          cout << endl << "Can't eat, vomiting?";
          cout << endl << "(y/n): ";
          cin >> input;
        }while(!(input == 'y' || input == 'n' ));

        if(input == 'y')
        {
          cout << "Some people can't eat when very nervous, others pig out. I"
            << " try eating small amounts of newtral food, like rice";
        }
        else
        {
          do
          {
            cout << endl << "Alien in stomach?";
            cout << endl << "(y/n): ";
            cin >> input;
          }while(!(input == 'y' || input == 'n' ));

          if(input == 'y')
          {
            cout << "Give it up you're history";
          }
          else
          {
            do
            {
              cout << endl << "Tried exercise?";
              cout << endl << "(y/n): ";
              cin >> input;
            }while(!(input == 'y' || input == 'n'));

            if(input == 'y')
            {
              do
              {
                cout << endl << "Caffeine, alchohol?";
                cout << endl << "(y/n): ";
                cin >> input;
              }while(!(input == 'y' || input == 'n'));

              if(input == 'y')
              {
                cout << "Drop coffe and booze as a test";
              }
              else
              {
                do
                {
                  cout << endl << "Diet mediation?";
                  cout << endl << "(y/n): ";
                  cin >> input;
                }while(!(input == 'y' || input == 'n'));

                if(input == 'y')
                {
                  do
                  {
                    cout << endl << "Changed job, life?";
                    cout << endl << "(y/n): ";
                    cin >> input;
                  }while(!(input == 'y' || input == 'n'));

                  if(input == 'y')
                  {
                    cout << "Sometimes, digestive tract problems are due to"
                      << " physical deformities or diesese. There may be"
                      << " medical help available, there may not be";
                  }
                  else
                  {
                    cout << "If stress is breaking you down, don't"
                      << " assume your're body at fault"; 
                  }
                }
                else
                {
                  cout << "Diet really affects digestion,"
                    << " mediation may help stres";
                }
              }
            }
            else
            {
              cout << "Execrcise is the cure all if you can do it";
            }    
          }
        }
      }
    }
    else
    {
      do
      {
        cout << endl << "Constant cramping pain?";
        cout << endl << "(y/n): ";
        cin >> input;
      }while(!(input == 'y' || input == 'n'));

      if(input == 'y')
      {
        do
        {
          cout << endl << "Worse sitting or lying down?";
          cout << endl << "(y/n): ";
          cin >> input;
        }while(!(input == 'y' || input == 'n'));

        if(input == 'y')
        {
          cout << endl << "I've gone days eating while standing"
            << " and sleeping while sitting - all bad";
        }
        else
        {
          do
          {
            cout << endl << "Worse fasting?";
            cout << endl << "(y/n): ";
            cin >> input;
          }while(!(input == 'y' || input == 'n'));

          if(input == 'y')
          {
            cout << endl << "May be ulcer or acid problem";
          }
          else
          {
            cout << endl << "May be torn, pulled abdominal muscle,"
              << " gall bladder, appendix, or worse";
          }
        }
      }
      else
      {
        do
        {
          cout << endl << "Burpng, gas?";
          cout << endl << "(y/n): ";
          cin >> input;
        }while(!(input == 'y' || input == 'n'));

        if(input == 'y')
        {
          cout << "Stay away from gassy and hard to digest food";
        }
        else
        {
          do
          {
            cout << endl << "Blood in toilet?";
            cout << endl << "(y/n): ";
            cin >> input;
          }while(!(input == 'y' || input == 'n'));

          if(input == 'y')
          {
            cout << "Minor bleeding may occur with major"
              << " bowel movements";
          }
          else
          {
            do
            {
              cout << endl << "Liquid noises?";
              cout << endl << "(y/n): ";
              cin >> input;
            }while(!(input == 'y' || input == 'n'));

            if(input == 'y')
            {
              cout << "Stop drinking booze";
            }
            else
            {
              do
              {
                cout << endl << "Poor healing, health?";
                cout << endl << "(y/n): ";
                cin >> input;
              }while(!(input == 'y' || input == 'n'));

              if(input == 'y')
              {
                cout << "May not be absorbing vitamins or nutrients,"
                  << " condition like Celiac";
              }
              else
              {
                do
                {
                  cout << endl << "Hard or frequent stools?";
                  cout << endl << "(y/n): ";
                  cin >> input;
                }while(!(input == 'y' || input == 'n'));

                if(input == 'y')
                {
                  do
                  {
                    cout << endl << "Good fiber eater?";
                    cout << endl << "(y/n): ";
                    cin >> input;
                  }while(!(input == 'y' || input == 'n'));

                  if(input == 'y')
                  {
                    cout << "Still suspect diet, maybe some else (alchohol,"
                      << " cheese, etc.) hardening stools";
                  }
                  else
                  {
                    cout << "Start reading labels. If you don't tolerate"
                      << " wheat, eat prunes, etc";
                  }
                }
                else
                {
                  do
                  {
                    cout << endl << "Occasional pain?";
                    cout << endl << "(y/n): ";
                    cin >> input;
                  }while(!(input == 'y' || input == 'n'));

                  if(input == 'y')
                  {
                    cout << "I hope for the best. Stray pains are tough"
                      << " to troubleshoot";
                  }
                  else
                  {
                    do
                    {
                      cout << endl << "Vomiting, losing weight?";
                      cout << endl << "(y/n): ";
                      cin >> input;
                    }while(!(input == 'y' || input == 'n'));

                    if(input == 'y')
                    {
                      cout << "The flue or other poising fequently cause"
                        << " vomiting, but I'd think about seeing a doctor"
                        << " if I ate well and kept vomiting for weeks or"
                        << " losing weight";
                    }
                    else
                    {
                      cout << "Could be a lot of bad things, I'm still"
                        << " trying";
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    cout << ", " << name << "." << endl;

    cout << endl << "Would you like to go again for another patient? ";
    cout << endl << "(y/n): ";
    cin >> input;

  }while(!(input == 'n'));
  
  cout << endl << "Goodbye!" << endl;

  return 0;
}
