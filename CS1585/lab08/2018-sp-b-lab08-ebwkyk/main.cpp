#include<iostream>
#include"list.h"
using namespace std;

int main()
{
  List<int> l;

  // Add 0,1,...,9 to the list
  for(int i = 0; i < 10; i++)
  {
    l.append(i);
  }


  // Pop the first thing off the list
  l.pop();


  // Walk down the list and print everything out
  Cell<int>* it = l.iterator();
  while(it != NULL)
  {
    cout << it->elem << endl;
    it = it->next;
  }

  return 0;
}

