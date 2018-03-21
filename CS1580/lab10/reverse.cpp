//Name: Evan WIlcox     Date: 10/25/17
//Class CS1580          Section: E
//Filename reverse.cpp
//Desc: 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Desc: readFile() reads from the given file into text[]
//Pre:  None
//Post: file is read into text[]
void readFile(char fileName[], char text[]);

//Desc: writeToFile() writes the reverse of text to file
//Pre:  text[] must be null terminated
//Post: reverse of text is written to file
void writeToFile(char fileName[], char text[]);

const int TEXT_LENGTH = 100;
const int FILE_NAME_LENGTH = 20;

int main()
{
  char fileName[FILE_NAME_LENGTH];
  char text[TEXT_LENGTH];

  cout << "Enter the name of the file: ";
  cin.getline(fileName, FILE_NAME_LENGTH);

  readFile(fileName, text);
  writeToFile(fileName, text);

  return 0;
}

void readFile(char fileName[], char text[])
{
  ifstream fin(fileName);
  fin.getline(text, TEXT_LENGTH);
  fin.close();
  return;
}

void writeToFile(char fileName[], char text[])
{
  ofstream fout(fileName);
  
  int length = 0;
  while(text[length] != '\0')
    length++;
 
  for(int i = length - 1;i >= 0;i--)
    fout << text[i];
 
  fout.close();
  return;
}
