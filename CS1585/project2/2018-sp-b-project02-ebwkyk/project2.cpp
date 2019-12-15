#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
  unordered_map<string, int> count;
  list<string> words;

  string word;

  while(cin >> word)
  {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    while(word.find('.') != string::npos)
    {
      word.erase(word.find('.'));
    }
    
    while(word.find(',') != string::npos)
    {
      word.erase(word.find(','));
    }
    
    while(word.find('#') != string::npos)
    {
      word.erase(word.find('#'));
    }
    
    while(word.find('"') != string::npos)
    {
      word.erase(word.find('"'));
    }
    
    while(word.find('\'') != string::npos)
    {
      word.erase(word.find('\''));
    }
    
    while(word.find(':') != string::npos)
    {
      word.erase(word.find(':'));
    }
    
    while(word.find('(') != string::npos)
    {
      word.erase(word.find('('));
    }
    
    while(word.find(')') != string::npos)
    {
      word.erase(word.find(')'));
    }
    
    while(word.find('[') != string::npos)
    {
      word.erase(word.find('['));
    }
    
    while(word.find(']') != string::npos)
    {
      word.erase(word.find(']'));
    }
    
    while(word.find('_') != string::npos)
    {
      word.erase(word.find('_'));
    }
    
    while(word.find(';') != string::npos)
    {
      word.erase(word.find(';'));
    }
    
    
    if(word != "")
    {
      count[word]++;
      
      if(count[word] == 1)
      {
        words.push_front(word);
      }
    }
  }

  list<string>::iterator i;
  for (i = words.begin(); i != words.end(); ++i)
  {
    cout << *i << "\t" << count[*i] << endl;;
  }

  return 0;
}
