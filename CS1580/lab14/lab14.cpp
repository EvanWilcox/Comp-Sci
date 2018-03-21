//
//
//
//

#include "meeseeks.h"

int main()
{
  meeseeks myMeeseeks[11];
  
  meeseeks Meeseeks;
 
  string purpose;

  cout << "Look at me! I'm Mr. Meeseeks. What's my purpose?" << endl;
  getline(cin, purpose);
  Meeseeks.setPurpose(purpose);
  
  cout << endl;
  cout << "Look at me! I'm Mr. Meeseeks. Here's my info." << endl;
  cout << "ID: M" << Meeseeks.getID() << endl;
  cout << "Purpose: " << Meeseeks.getPurpose() << endl;

  
  return 0;
}
