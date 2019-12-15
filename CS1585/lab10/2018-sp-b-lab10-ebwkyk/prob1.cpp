#include<iostream>
#include<string>
#include"vector.h"
using namespace std;

int main()
{
  Vector<string> data;
  string buf;

  while(getline(cin, buf))
  {
    if(buf[0] != '#')
    {
      cout << buf << endl;
      data.push_back(buf);
    }
  }

  for(unsigned int i = 0; i < data.length(); i++)
  {
    cout << data[i] << endl;
  }

  return 0;
}
