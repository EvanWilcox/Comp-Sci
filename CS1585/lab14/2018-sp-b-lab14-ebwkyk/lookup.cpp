#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <fstream>

using std::map;
using std::tuple;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::make_tuple;
using std::ifstream;
using std::get;

int main(int argc, char *argv[])
{
  if(argc > 3)
  {
    cout << "Too many arguments, only two needed." << endl;
    return 0;
  }
  else if(argc < 3)
  {
    cout << "Not enough arguments, two needed." << endl;
    return 0;
  }
  
  ifstream fin(argv[1]);
  auto name = argv[2];
  
  int one, two, three;
  string temp;
  
  map<string, tuple<int, int, int>> phoneBook;

  while(fin >> temp)
  {
    fin >> one;
    fin >> two;
    fin >> three;

    phoneBook[temp] = make_tuple(one, two, three);
  }
  
  fin.close();


  if(phoneBook.find(name) != phoneBook.end())
  {
    cout << get<0>(phoneBook[name]) << " " << get<1>(phoneBook[name]) << " " << get<2>(phoneBook[name]) << endl;
  }
  else
  {
    ifstream fin(argv[1]);

    while(getline(fin, temp))
    {
      cout << temp << endl;
    }

    fin.close();
  }


  return 0;
}
