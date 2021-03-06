/*
* Author: Evan Wilcox
* File: Node.h Date: 4/23/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: Header file for a Node class
*/

#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
using std::string;
using std::ostream;

/*
* Class: Node
* Brief: A class that pairs a name, latitude and longitude in to a node.
*/
struct Node
{
    string m_name;  // name of the node
    float m_lat;    // latitude of the node
    float m_long;   // longitude of the node

    /*
    * Function  : Node
    * Brief     : Constructor using a initialization list
    * Pre       : None
    * Post      : A Node object is created
    * Param n   : name to be given to m_name
    * Param lat : latitude to be given to m_lat
    * Param lon : longitude to be given to m_lon
    * Return    : None
    */
    Node(string n, float lat, float lon): m_name(n), m_lat(lat), m_long(lon){}
};

#endif