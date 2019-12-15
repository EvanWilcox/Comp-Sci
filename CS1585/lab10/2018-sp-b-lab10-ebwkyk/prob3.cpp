#include<iostream>
#include"vector.h"
using namespace std;

int main()
{
  Vector<char*> lines;
  char* buf = new char[2000];
  unsigned int totalChars = 0;

  while(cin.getline(buf,2000))
  {
    lines.push_back(buf);
    for(int i = 0;buf[i] != '\0';i++)
    {
      totalChars++;
    }

    buf = new char[2000];


    cout << totalChars / lines.length() << endl;
  }

  return 0;
}
