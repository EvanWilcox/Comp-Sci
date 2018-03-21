//Names: Evan Wilcox, Andrew Henningsen     Date: 11/3/17
//Class: CS1570       
//Filename: hw08.h
//Desc: Header file for hw08.cpp

#ifndef HW08_H
#define HW08_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

// Global constants
const int MIN_REVERSE_WORDS = 3;

const int MAX_NUM_WORDS = 50;
const int MAX_NUM_LINES = 10;

const int NUM_REPLACE_WORDS = 6;
const int NUM_EXCLUDED_WORDS = 4;

const string DECRYPTED_WORDS[NUM_REPLACE_WORDS] = {"he", "his", "your", 
  "their", "you", "penguins"};
const string ENCRYPTED_WORDS[NUM_REPLACE_WORDS] = {"she", "her", "my", "there",
  "i", "frogs"};
const string EXCLUDED_WORDS[NUM_EXCLUDED_WORDS] = {"--like--", "--errr--",
  "--nstuff--", "--umm--"};

const string FILE_IN = "encrypted.dat";
const string FILE_OUT = "decrypted.dat";


// Function Prototypes

// Desc: Reads in data from file "encrypted.dat" 
// Pre:  "encrypted.dat" must exist. numLines must be 1. wordCount[n] = 0.
//       the size of wordCount must be equal or greater than the size of
//       arr.
// Post: Data will be read in and stored by sentences ands words in 
//       arr[][] and wordCount will hold the number words in each line.
void readIn(string arr[][MAX_NUM_WORDS], int& numLines, int wordCount[]);

// Desc: Pair wise swaps the words in odd number sentences
// Pre:  wordCount size must be greater or equal to arr size. numLines must be
//       less than arrs size
// Post: the words will be pairwise swapped.
void replaceWordPairs(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[]);

// Desc: Replaces the first and last words of the sentence
// Pre:  wordCount size must be greater or equal to arr size. numLines must be
//       less than arrs size
// Post: the sentences first and last words will be swapped.
void replaceFirstLastWords(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[]);

// Desc: Swaps an apostrophe with the character after it.
// Pre:  wordCount size must be greater or equal to arr size. numLines must be
//       less than arrs size

// Post: the apostrophe will be swapped with the character after it.
void punctuation(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[]);

// Desc: Swaps encrypted words with decrypted words.
// Pre:  wordCount size must be greater or equal to arr size. numLines must be
//       less than arrs size
// Post: The encrypted words will be swapped with the decrypted words.
void replaceWords(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[]);

// Desc: Prints all the sentences of lines to the screen.
// Pre:  wordCount size must be greater or equal to arr size. numLines must be
//       less than arrs size
// Post: All sentences will be printed to the screen.
void print(const string lines[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[]);

// Desc: Reverses the middle word of every even sentence with at least 3 words.
// Pre:  wordCount size must be greater or equal to arr size. numLines must be
//       less than arrs size
// Post: the middle word of every even sentence with at least 3 words will be 
//       reversed
void reverseWord(string arr[][MAX_NUM_WORDS], const int numLines,
    const int wordCount[]);

#endif
