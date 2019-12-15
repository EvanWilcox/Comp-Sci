/*
* Author : Evan Wilcox
* File : EdmondsKarp.h 
* Date : 5/2/2019
* Class : CS 2500
* Instructor : Bruce McMillan
* Brief : Header file for Edmonds-Karp algorithm
*/

#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include <vector>
#include <queue>
#include <iostream>
#include <assert.h>
#define INF 0x3f3f3f3f 

using namespace std;

/*
* Class :   EdmondsKarp
* Brief :   EdmondsKarp algorithm implemented in a class
*/
class EdmondsKarp
{
    private :  
        int n;                              // number of verticies
        vector<vector<int>> capacity;       // 2d capacity matrix 
        vector<vector<int>> adj;            // adjency list
        bool debug;                         // indicates if debug mode is enabled

    public :  
        /*
        * Function : EdmondsKarp
        * Brief : constructor initializes n, capacity, adj
        * Pre : none
        * Post : EdmondsKarp object is created
        * Param n : number of verticies in the graph
        * Return : none
        */
        EdmondsKarp(int n, bool d);

        /*
        * Function : addEdge
        * Brief : adds an edge to adj and capacity
        * Pre : u, v, c are ints
        * Post : a edge is added to adj and capacity
        * Param u : first vertex of edge  
        * Param v : second vertex of edge
        * Param c : capacity of edge
        * Return : none
        */
        void addEdge(int u, int v, int c);

        /*
        * Function : bfs
        * Brief : breadth first search to find closest vertex
        * Pre : src and end are positive integers
        * Post : parent stores stores the graph in parent array form 
        * Param src : starting vertex
        * Param end : ending vertex
        * Param parent : vector that will store the graph in parent array form 
        * Return : flow of closest vertex
        */
        int bfs(int src, int end, vector<int>& parent);

        /*
        * Function : maxFlow
        * Brief : computes the max flow of the graph strored in adj and capacity
        * Pre : src and end are positive integers
        * Post : the maxFlow is returned
        * Param src : starting vertex
        * Param end : ending vertex
        * Return : max flow of the graph stored in adj and capacity
        */
        int maxflow(int src, int end);
};

#endif