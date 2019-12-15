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
#define INF 0x3f3f3f3f 
using std::cout;
using std::ofstream;
using std::list;
using std::vector;
using std::pair;
using std::endl;
using std::make_pair;
using std::priority_queue;
using std::greater;
using std::min;


struct Edge 
{ 
    // To store current flow and capacity of edge 
    int flow, capacity; 
  
    // An edge u--->v has start vertex as u and end 
    // vertex as v. 
    int u, v; 
  
    Edge(int flow, int capacity, int u, int v) 
    { 
        this->flow = flow; 
        this->capacity = capacity; 
        this->u = u; 
        this->v = v; 
    } 
}; 
  
// Represent a Vertex 
struct Vertex 
{ 
    int h, e_flow; 
  
    Vertex(int h, int e_flow) 
    { 
        this->h = h; 
        this->e_flow = e_flow; 
    } 
}; 




/*
* Class: Graph
* Brief: A class that implements a graph and multiple minimum spamming tree algorithms.
*/
class Graph
{
    private:
        vector<Node> *V;                                // pointer to a vector of verticies
        list<pair<int, float>> *adj;                    // adjency list
        vector<vector<pair<int, pair<int, int>>>> flow;            // flow adjency matrix, {u, {flow, capacity}}

        


        vector<Vertex> ver;
        vector<Edge> edge;

        // Function to push excess flow from u 
        bool push(int u); 
    
        // Function to relabel a vertex u 
        void relabel(int u); 
    
        // This function is called to initialize 
        // preflow 
        void preflow(int s); 
    
        // Function to reverse edge 
        void updateReverseEdgeFlow(int i, int flow);

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

        //void removeEdge(int u, int v);
    
        /*
        * Function  : 
        * Brief     : 
        * Pre       : 
        * Post      : 
        * Param src : 
        * Return    : 
        */
        vector<int> dijkstra(int src, int end);

        /*
        * Function  : 
        * Brief     : 
        * Pre       : 
        * Post      : 
        * Param src : 
        * Return    : 
        */
        int EdmondsKarp(int src, int end);

        /*
        * Function  : print
        * Brief     : prints adj
        * Pre       : V is a vector of Nodes, adj is an adjencency list
        * Post      : an adjencency list is printed to the screen
        * Return    : none
        */
        void print(string file);

        void test();

        // function to add an edge to graph 
        void addedge(int u, int v, int w); 
    
        // returns maximum flow from s to t 
        int getMaxFlow(int s, int t); 
};







#endif