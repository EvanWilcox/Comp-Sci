//Name: EVAN WILCOX       Date: 10/13/17
//Class: CS1570           Section: B
//File: walkSimulator.h
//Desc: Heder file for walkSimulator.cpp

#ifndef WALK_SIM_H
#define WALK_SIM_H

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


//CONSTANTS

const int NUM_SIMS = 500;       
const int MAX_DEC_P = 500;      

const int HOME_RADIUS = 10;
const int COP_RADIUS = 5;
const int PENGUIN_RADIUS = 175;

const int HOME_X = 0;
const int HOME_Y = 0;

const int HANS_MIN = 50;
const int HANS_MAX = 100;

const int PENGUIN_MIN = 20;
const int PENGUIN_MAX = 50;

const char NORTH = 'N';
const char SOUTH = 'S';
const char EAST = 'E';
const char WEST = 'W';

const int COP_TURN_MAX = 10;

//FUNCTION DECLRATIONS

//Desc: returns a random distacnce between(inclusive) rand_max and rand_min.
//Pre:  rand_max and rand_min must be positive
//Post: random int between rand_max and rand_min is returned
int rand_distance(const int rand_max, const int rand_min);

//Desc: given x and y coords, lastDirection, and newDirection x and y coords 
//      are changed
//Pre:  lastDirection & newDirection must be chars 'N', 'S', 'E', 'W'
//Post: distance is + or - to x_pos or y_pos and lastDirection is updated
void move_random(int& x_pos, int& y_pos, const int distance,
  char& lastDirection, const int newDirection);

//Desc: changes x_pos or y_pos distance with i bias towards (0,0)
//Pre:  direction must be int between 1-100
//Post: new direction is calculated and distance is + or - to x_pos or y_pos
void move_guided(int& x_pos, int& y_pos, const int distance,
  const int direction);

//Desc: swaps values of x_pos and y_pos
//Pre:  None
//Post: x_pos and y_pos values are swapped
void swap(int& x_pos, int& y_pos);

//Desc: calculates distance between two things given two x and y coordinates
//Pre:  None
//Post: distance is returned
float distance_between(const int one_x, const int one_y, const int two_x,
  const int two_y);

//Desc: sets start_x and start_y to end_x and end_y respecively 
//Pre:  None
//Post: start_x is set to end_x and start_y is set to end_y
void jump_to_location(int& start_x, int& start_y, const int end_x,
  const int end_y);

//Desc: calculates and prints statistics of hautling conditions
//Pre:  None
//Post: Statistics are printed to screen
void output(const int hansHome, const int hansLost, const int freeRide,
  const int jail);

//Desc: Prints x_pos, y_pos and name
//Pre:  None
//Post: x_pos, y_pos, and name are printed to screen
void print_pos(const int x_pos, const int y_pos, const char name);

#endif
