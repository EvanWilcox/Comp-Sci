/*
* Author: Evan Wilcox
* File: Graph.h Date: 4/23/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: Header file for a Graph class
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <queue>
#include <bits/stdc++.h> 
#include "Node.h"
#include "DisjointSets.h"
#define INF 0x3f3f3f3f 
using namespace std;

/*
* Class: Graph
* Brief: A class that implements a graph and multiple minimum spamming tree algorithms.
*/
class Graph
{
    private:
        vector<Node> *V;                                // pointer to a vector of verticies
        list<pair<int, float>> *adj;                    // adjency list
        vector< pair<float, pair<int, int>>> edges;     // vector of edges

    public:
        /*
        * Function  : Graph
        * Brief     : Constructor
        * Pre       : none
        * Post      : A Graph object is created, adj = a new adjency list
        * Param V   : a pointer to a vector of Nodes
        * Return    : none
        */
        Graph(vector<Node> *V);  

        /*
        * Function  : ~Graph
        * Brief     : Deconstructor
        * Pre       : none
        * Post      : A Graph object is deleted
        * Return    : none
        */
        ~Graph();
    
        /*
        * Function  : addEdge
        * Brief     : adds an edge to the edges vector and adds a connection in adj
        * Pre       : none
        * Post      : A edge is add to edges and a connection is add to adj
        * Param u   : index of first node of edge
        * Param v   : index of second node of edge
        * Param w   : weight of edge
        * Return    : none
        */
        void addEdge(int u, int v, float w); 
    
        /*
        * Function  : PrimMST
        * Brief     : Creates a minimum spanning tree using Prim's algorithm
        * Pre       : V is a vector of Nodes, adj is an adjency list
        * Post      : a MST is printed
        * Param src : source node to start the MST at
        * Return    : MST in a Graph class
        */
        Graph PrimMST(int src);

        /*
        * Function  : KruskalMST
        * Brief     : Creates a minimum spanning tree using Kruskal's algorithm
        * Pre       : V is a vector of Nodes, edges is a vector of edges
        * Post      : a MST is printed
        * Return    : MST in a Graph class
        */
        Graph KruskalMST();

        /*
        * Function  : print
        * Brief     : prints adj
        * Pre       : V is a vector of Nodes, adj is an adjencency list
        * Post      : an adjencency list is printed to the screen
        * Return    : none
        */
        void print();
};

#endif