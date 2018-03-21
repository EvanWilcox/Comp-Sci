//Names: Evan Wilcox, Andrew Henningsen     Date: 11/3/17
//Class: CS1570       
//Filename: hw08.cpp
//Desc: Reads in an encrypted message, decrypts and writes it to decrypted.dat

#include "hw08.h"

int main()
{
  // Declare variables
  string lines[MAX_NUM_LINES][MAX_NUM_WORDS] = {""};
  int numLines = 1;
  int wordCount[MAX_NUM_LINES] = {0};

  // Decrypt data
  readIn(lines, numLines, wordCount);
  replaceWords(lines, numLines, wordCount);
  punctuation(lines, numLines, wordCount);
  replaceWordPairs(lines, numLines, wordCount);
  replaceFirstLastWords(lines, numLines, wordCount);
  reverseWord(lines, numLines, wordCount);

  // Output data
  print(lines, numLines, wordCount);

  return 0;
}
