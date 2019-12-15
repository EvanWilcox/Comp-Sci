/*
* Author: Evan Wilcox
* File: Graph.cpp Date: 4/23/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: Implementation file for a Graph class
*/

#include "Graph.h"

Graph::Graph(vector<Node> *V) 
{ 
    this->V = V; 
    adj = new list<pair<int, float>> [V->size()]; 
} 


Graph::~Graph()
{
    delete adj;
}

  
void Graph::addEdge(int u, int v, float w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
    
    edges.push_back({w, {u, v}});
} 
  

Graph Graph::PrimMST(int src) 
{ 
    // Priority queue to store vertices
    priority_queue<pair<int, float>, vector<pair<int, float>> , greater<pair<int, float>>> Q; 
  
    // Vector to store distances
    vector<float> dis(V->size(), INF); 
  
    // To store parent array which stores MST 
    vector<int> parent(V->size(), -1); 
  
    // Keeps track if an edge is in MST
    vector<bool> inMST(V->size(), false); 
  
    // Insert src in priority queue and set it to 0. 
    Q.push(make_pair(0, src)); 
    dis[src] = 0; 
  
    while (!Q.empty()) 
    { 
        int u = Q.top().second; 
        Q.pop(); 
  
        inMST[u] = true;  // Include vertex in MST 
  
        // i is used to get all adjacent vertices of a vertex 
        list< pair<int, float> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent of u. 
            int v = (*i).first; 
            float weight = (*i).second; 
  
            //  If v is not in MST and weight of (u,v) is smaller than current dis of v 
            if (inMST[v] == false && dis[v] > weight) 
            { 
                // Updating dis of v 
                dis[v] = weight; 
                Q.push(make_pair(dis[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  
    Graph MST(V);

    for(int i = 1; i < V->size(); i++)
    {
        MST.addEdge(i, parent[i], dis[i]);
        cout << dis[i] << endl;
    }

    return MST;
} 


Graph Graph::KruskalMST() 
{ 
    Graph MST(V);

    // Sort edges in increasing order based on distance
    sort(edges.begin(), edges.end()); 
  
    // Create disjoint sets 
    DisjointSets ds(V->size()); 
  
    // Iterate through all sorted edges 
    vector< pair<float, pair<int, int>> >::iterator it; 
    for (it = edges.begin(); it != edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        // Check if the selected edge is creating a cycle or not
        if (set_u != set_v) 
        { 
            MST.addEdge(u, v, it->first);

            // Merge two sets 
            ds.merge(set_u, set_v); 
        } 
    }

    return MST; 
}


void Graph::print()
{
    ofstream fout;
    fout.open("out.txt");
    
    fout << "2" << endl;

    for(int x = 0; x < V->size(); x++)
    {
        fout << (*V)[x].m_name << ": ";
        list< pair<int, float> >::iterator y; 
        for (y = adj[x].begin(); y != adj[x].end(); ++y) 
        {
            fout << (*V)[y->first].m_name << ", ";
        }   
        fout << endl << endl;
    }

    fout.close();
}
