//Name: EVAN WILCOX       Date: 10/20/17
//Class: CS1570           Section: B
//Filename: penguins.h
//Desc: 

#ifndef PENGUINS_H
#define PENGUINS_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int NUM_PENGUINS = 50;

const int WEIGHT_MIN = 4;
const int WEIGHT_MAX = 20;

const int WINGSPAN_MIN = 4;
const int WINGSPAN_MAX = 24;

const float NEUROTICISM_MIN = 1.00;
const float NEUROTICISM_MAX = 10.00;

const float EXTROVERSION_MIN = -5.00;
const float EXTROVERSION_MAX = 5.00;

const string SUPER_PENG_NAME = "Jerry";
const float WINGSPAN_MULTIPLIER = 1.7;
const float WEIGHT_MULTIPLIER = 0.6;

const int NUM_CATEGORIES = 4;

const int CATEGORY0 = 0;
const int CATEGORY1 = 1;
const int CATEGORY2 = 2;
const int CATEGORY3 = 3;

const float CATEGORY0_MIN = 1.00;
const float CATEGORY0_MAX = 4.00;
const float CATEGORY1_MIN = 4.00;
const float CATEGORY1_MAX = 6.00;
const float CATEGORY2_MIN = 6.00;
const float CATEGORY2_MAX = 8.00;
const float CATEGORY3_MIN = 8.00;
const float CATEGORY3_MAX = 10.00;

const int MAX_NUM_BREEDERS = NUM_PENGUINS * 0.1;

const string NAMES[NUM_PENGUINS] = {"Abigail", "Addison", "Aiden", "Alexander", 
  "Amelia", "Andrew", "Anthony", "Aubrey", "Ava", "Avery", "Benjamin", 
  "Charlotte", "Chole", "Daniel", "David", "Elijah", "Elizabeth", "Ella", 
  "Emily", "Emma", "Ethan", "Evelyn", "Gabriel", "Grace", "Harper", "Isabella", 
  "Jackson", "Jacob", "James", "Jayden", "Joesph", "Joshua", "Liam", "Lillian",
  "Logan", "Lucas", "Madison", "Mason", "Matthew", "Mia", "Michael", "Natalie",
  "Noah", "Olivia", "Samuel", "Sofia", "Sophia", "Victoria", "William", "Zoey"};

struct Personality
{
  float m_neuroticism;
  float m_extroversion;
};

struct Physique
{
  int m_weight;
  int m_wingSpan; 
};

struct Penguin
{
  string m_name;
  Personality m_personality;
  Physique m_physique;
};


//Desc: rand_wingSpan() returns random wingspan value
//Pre:  None.
//Post: Random value is returned.
int rand_wingSpan();

//Desc: rand_Weight() returns random weight value
//Pre:  None.
//Post: Random value is returned.
int rand_weight();

//Desc: rand_Neuroticism() returns random neuroticism value
//Pre:  None.
//Post: Random value is returned.
float rand_neuroticism();

//Desc: rand_extroversion() returns random extroversion value
//Pre:  None.
//Post: Random value is returned.
float rand_extroversion();

//Desc: print_penguin() prints a penguin's info to the screen
//Pre:  None.
//Post: A penguin's info is printed to the screen
void print_penguin(const Penguin p);

//Desc: print_penguins() prints an array of penguin's info to the screen
//Pre:  Length of array must be NUM_PENGUINS.
//Post: An array of penguin's info is printed to the screen
void print_penguins(const Penguin p[], const int num = NUM_PENGUINS);

//Desc: 
//Pre:  
//Post: 
void print_penguins(const Penguin p[], const int index[], const int num = NUM_PENGUINS);

//Desc: randomize_penguins() randomizes the info of a given Penguin array
//Pre:  Length of array must be NUM_PENGUINS.
//Post: Info is randomized
void randomize_penguins(Penguin p[]);

//Desc: sort() sorts dataArray[] least to greatest and creates an indexArray[]
//      startig at an index of start
//Pre:  indexArray[n] = n
//Post: dataArray[] and indexArray[] are sorted.
void sort(int dataArray[], int indexArray[], const int start = 0);

//Desc: sort() sorts dataArray[] least to greatest and creates an indexArray[]
//      startig at an index of start
//Pre:  indexArray[n] = n
//Post: dataArray[] and indexArray[] are sorted.
void sort(float dataArray[], int indexArray[], const int start = 0);

//Desc: get_wingSpan_array() extracts wingSpans from dataArray[] and puts 
//      them in copyArray[].
//Pre:  None.
//Post: wing spans are put into dataArray[].
void get_wingSpan_array(const Penguin dataArray[], int copyArray[]);

//Desc: get_neuroticism_array() extracts neuroticism from dataArray[] and puts 
//      them in copyArray[].
//Pre:  None.
//Post: neuroticisms are put into dataArray[].
void get_neuroticism_array(const Penguin dataArray[], float copyArray[]);

//Desc:
//Pre:  
//Post: 
void create_index(int index[]);

//Desc: get_superPenguin() finds the super penguin given at least 2 penguins
//Pre:  breeders[] must contain at least 2 penguin.
//Post: Super Penguin is returned.
Penguin get_superPenguin(const Penguin breeders[], const int numBreeders);

#endif
