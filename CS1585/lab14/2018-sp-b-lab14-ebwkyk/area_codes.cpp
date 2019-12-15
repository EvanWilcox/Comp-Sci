#include <iostream>
#include <set>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::ifstream;
using std::string;


int main(int argc, char *argv[])
{
  if(argc > 2)
  {
    cout << "Too many arguments, only two needed." << endl;
    return 0;
  }
  else if(argc < 2)
  {
    cout << "Not enough arguments, two needed." << endl;
    return 0;
  }
  
  ifstream fin(argv[1]);
  
  string temp;
  int one, two, three;
  
  set<int> phoneBook;

  while(fin >> temp)
  {
    fin >> one;
    fin >> two;
    fin >> three;

    phoneBook.insert(one);
  }
  
  fin.close();

  return 0;
}

