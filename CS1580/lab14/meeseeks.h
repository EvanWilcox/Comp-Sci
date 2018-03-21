//
//
//
//

#ifndef MEESEEKS_H
#define MEESEEKS_H

#include <iostream>
#include <string>
using namespace std;

class meeseeks
{
  private:
    int m_ID;
    string m_purpose;
    static int m_numMeeseeks;

  public:
    meeseeks();

    static int generateID();

    void setPurpose(const string p);
    string getPurpose() const;
    
    int getID() const;


};




#endif
