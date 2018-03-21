//NameS: Evan Wilcox, Andrew Henngingsen      Date: 11/3/17
//Class: CS1570
//Filename: hw08Functions.cpp
//Desc: Functtion implementation file for hw08.h

#include "hw08.h"

void readIn(string lines[][MAX_NUM_WORDS], int& numLines, int wordCount[])
{
  ifstream fin(FILE_IN.c_str());
  string newWord;
  bool isExcludedWord;

  while(fin >> newWord)
  {
    isExcludedWord = false;
    for(int i = 0;i < NUM_EXCLUDED_WORDS;i++)
    {
      if(!(newWord.compare(EXCLUDED_WORDS[i])))
      {
        isExcludedWord = true;
      }
    }
    if(!isExcludedWord)
    {
      lines[numLines][wordCount[numLines]] += newWord;
      lines[numLines][wordCount[numLines]] += " ";
      wordCount[numLines]++;

      if(!(newWord.find(".") == string::npos))
      {
        numLines++;
      }
    }
  }
  fin.close();
  return;
}

void replaceWordPairs(string arr[][MAX_NUM_WORDS], const int numLines, 
    const int wordCount[])
{
  int stop;

  for(int i = 1;i < numLines;i+=2)
  {
    stop = wordCount[i];
    if(stop % 2 == 1)
    {
      stop -= 1;
    }

    for(int j = 0;j < stop;j+=2)
    {
      string temp = arr[i][j];
      if(j == 0)
      {  
        if(!(temp[0] == 'I'))
        {
          temp[0] = tolower(temp[0]);
        }
        arr[i][j+1][0] = toupper(arr[i][j+1][0]);
      }
      arr[i][j] = arr[i][j+1];
      arr[i][j+1] = temp;

      if(!(arr[i][j].find(".") == string::npos))
      {
        arr[i][j].erase(arr[i][j].end()-2, arr[i][j].end()-1);
        arr[i][j+1].erase(arr[i][j+1].end()-1);
        arr[i][j+1] += ".";
      }
    }
  }
  return;
}

void replaceFirstLastWords(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[])
{
  string temp;
  for(int i = 2;i < numLines;i+=2)
  {
    arr[i][0].erase(arr[i][0].end()-1);
    arr[i][0] += ".";

    arr[i][wordCount[i]-1].erase(arr[i][wordCount[i]-1].end()-2);
    temp = arr[i][0];

    if(!(temp[0] == 'I'))
      temp[0] = tolower(temp[0]);

    arr[i][0] = arr[i][wordCount[i]-1];
    arr[i][0][0] = toupper(arr[i][0][0]);
    arr[i][wordCount[i]-1] = temp;
  }
  return;
}

void punctuation(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[])
{
  string word, temp;
  int index;
  for(int i = 1;i< numLines;i++)
  {
    for(int j = 0;j < wordCount[i];j++)
    {
      word = arr[i][j];
      index = word.find('\'');
      if(index >= 0 && !(index == static_cast<int>(word.length()-1)))
      {
        word[index] = word[index + 1];
        word[index+1] = '\'';
      } 
      else if(index == static_cast<int>(word.length()-1))
      {
        word.erase(word.length()-1);
        word.insert(0, "\'");
      }
      arr[i][j] = word;
    }
  }
  return;
}

void replaceWords(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[])
{
  string word;
  bool hasPeriod, changed;
  for(int i = 1;i< numLines;i++)
  {
    for(int j = 0;j < wordCount[i];j++)
    {
      hasPeriod = false;
      changed = false;
      word = arr[i][j].substr(0, arr[i][j].length()-1);
      word[0] = tolower(word[0]);

      if(word.find('.') != string::npos)
      {
        hasPeriod = true;
        word.erase(word.length() - 1);
      }

      for(int k = 0;k < NUM_REPLACE_WORDS;k++)
      {
        if(!(word.compare(ENCRYPTED_WORDS[k])))
        {
          word = DECRYPTED_WORDS[k];
          changed = true;
        }
      }
      if (hasPeriod)
        word += ".";
      word += arr[i][j][arr[i][j].length()-1];
      if(changed)
        arr[i][j] = word;
    }
  }
  return;
}

void print(const string lines[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[])
{
  ofstream fout(FILE_OUT.c_str());

  for(int i = 1;i <= numLines;i++)
  {    
    for(int j = 0; j < wordCount[i]; j++)
    {
      fout << lines[i][j];
    }
    fout << endl;
  }
  fout.close();
  return;
}

void reverseWord(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[])
{
  string word;
  char temp;
  for(int i = 2;i < numLines;i+=2)
  {
    if(wordCount[i] % 2 && wordCount[i] >= 3)
    {
      word = arr[i][wordCount[i]/2];
      word.erase(word.length()-1);
      for(unsigned int j = 0;j < word.length()/2;j++)
      {
        temp = word[j];
        word[j] = word[word.length()-j-1];
        word[word.length()-j-1] = temp;
      }
      word += " ";
      arr[i][wordCount[i]/2] = word;
    }
  }
  return;
}
