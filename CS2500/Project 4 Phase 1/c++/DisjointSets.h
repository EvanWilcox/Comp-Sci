/*
* Author: Evan Wilcox
* File: DisjointSets.h Date: 4/23/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: Header file for a Disjoint Set class
*/

#ifndef DISJOINT_H
#define DISJOINT_H

/*
* Class: DisjointSets
* Brief: A class that implements disjoint sets as a data type
*/
struct DisjointSets 
{ 
    int *parent;    // array that stores the parent of each node
    int *rnk;       // array that stores the rank of each node
    int n;          // number of nodes in set
  
    /*
    * Function  : DisjointSets
    * Brief     : Constructor
    * Pre       : none
    * Post      : A DisjointSets object is created
    * Param n   : the number of nodes in the set
    * Return    : none
    */
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        // Initially, all vertices are in different sets and have rank 0. 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
  
    /*
    * Function  : find
    * Brief     : Find the parent of a node
    * Pre       : none
    * Post      : none
    * Param u   : node whose parent will be found
    * Return    : parent of node u
    */
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    /*
    * Function  : merge
    * Brief     : unions two sub trees
    * Pre       : none
    * Post      : two sub trees are merged
    * Param x   : root of tree 1 to merge
    * Param y   : root of tree 2 to merge
    * Return    : none
    */
    void merge(int x, int y) 
    { 
        x = find(x);
        y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 

#endif