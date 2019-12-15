/*
* Author: Evan Wilcox
* File: Graph.cpp Date: 4/23/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: Implementation file for a Graph class
*/

#include "Graph.h"


void Graph::test()
{
    for(int u = 0; u < flow.size(); u++)
    {
        //cout << "===" << (*V)[u].m_name << "===" << endl;
        for(int v = 0; v < flow[u].size(); v++)
        {
            //cout << u << endl;
            //cout << flow[u].size() << endl;

            //cout << (*V)[flow[u][v].first].m_name << ", " << flow[u][v].second.first << ", " << flow[u][v].second.second << endl;
            //cout << u << ", " << v << endl;
        }
    }
    
    cout << (*V)[785].m_name << endl;
    for(int i = 0; i < flow[785].size(); i++)
    {
        cout << (*V)[flow[785][i].first].m_name << endl;
    }

}


Graph::Graph(vector<Node> *V) 
{ 
    this->V = V; 
    adj = new list<pair<int, float>> [V->size()]; 

    flow.resize(V->size());

    // code from geeksforgeeks
    //this->V = V; 
  
    // all vertices are initialized with 0 height 
    // and 0 excess flow 
    for (int i = 0; i < V->size(); i++) 
        ver.push_back(Vertex(0, 0)); 


    
} 


Graph::~Graph()
{
    delete adj;
}

  
void Graph::addEdge(int u, int v, float w) 
{ 
    if(u != v)
    {
        adj[u].push_back(make_pair(v, w)); 
        adj[v].push_back(make_pair(u, w)); 

        flow[u].push_back(make_pair(v, make_pair(0, 1)));
        //flow[v].push_back(make_pair(u, make_pair(0, 1)));
    }
    else
    {
        adj[u].push_back(make_pair(v, w)); 
    }

    //edge.push_back(Edge(0, 1, u, v)); 
} 

/*
void Graph::removeEdge(int u, int v)
{
    if(u != v)
    {
        vector<pair<int, pair<int, int>>>::iterator it;
        for(it = flow[u].begin(); it < flow[u].end(); it++)
        {
            if((*it).first == v)
            {
                flow[u].erase(it);
            }
        }

        for(it = flow[v].begin(); it < flow[v].end(); it++)
        {
            if((*it).first == u)
            {
                flow[v].erase(it);
            }
        }
        
    }
}
*/

vector<int> Graph::dijkstra(int src, int end) 
{ 
    // Priority queue to store vertices
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> Q; 
  
    // Vector to store distances
    vector<float> dis(V->size(), INF); 
  
    // To store parent array
    vector<int> parent(V->size(), -1); 
  
    // Insert src in queue and set it to 0. 
    Q.push(make_pair(0, src)); 
    dis[src] = 0; 
  
    while (!Q.empty()) 
    { 
        int u = Q.top().second; 
        Q.pop(); 
  
        // i is used to get all adjacent vertices of a vertex 
        for(int i = 0; i < flow[u].size(); i++)
        { 
            // Get vertex label and weight of current adjacent of u. 
            int v = flow[u][i].first; 
            int flo = flow[u][i].second.first;
            int capacity = flow[u][i].second.second; 
  
            //  If v is not in MST and weight of (u,v) is smaller than current dis of v 
            if ((dis[v] > dis[u] + capacity)) 
            {   
                if(flo < capacity)
                {
                    // Updating dis of v 
                    dis[v] = dis[u] + capacity; 
                    Q.push(make_pair(dis[v], v)); 
                    parent[v] = u; 
                    //removeEdge(u, v);
                }             
            } 
        } 
    } 
  
    // vector that will contain the indexes of vertexes in the solution
    vector<int> solution;
    int j = end;

    while(j != -1)
    {
        solution.push_back(j);
        j = parent[j];
    }
    reverse(solution.begin(), solution.end());

    return solution;
} 

int Graph::EdmondsKarp(int src, int end)
{
    // vector sotring the augmented path
    vector<int> s = dijkstra(src, end);
    int maxFlow = 0;

    // while a path from src to end still exists
    while(s.size() > 1)
    {
        maxFlow++;
        for(int i = 0; i < s.size(); i++)
        {
            //cout << (*V)[s[i]].m_name << endl;
        }

        // update flow for edges in the augmented path
        for(int i = 0; i < s.size()-1; i++)
        {
            for(int u = 0; u < flow[s[i]].size(); u++)
            {
                if(flow[s[i]][u].first == s[i+1])
                {
                    flow[s[i]][u].second.first = flow[s[i]][u].second.second;
                    //maxFlow += flow[s[i]][u].second.first;
                }
            }
        }

        // find new path
        s = dijkstra(src, end);
    };

    return maxFlow;
}


void Graph::print(string file)
{
    ofstream fout;
    fout.open(file);
    
    fout << file << endl;

    for(int x = 0; x < V->size(); x++)
    {
        fout << (*V)[x].m_name << ": ";
        list< pair<int, float> >::iterator y; 
        for (y = adj[x].begin(); y != adj[x].end(); ++y) 
        {
            fout << (*V)[y->first].m_name << ", ";
        }   
        fout << endl;
    }

    fout.close();
}


/*
Graph::Graph(int V) 
{ 
    this->V = V; 
  
    // all vertices are initialized with 0 height 
    // and 0 excess flow 
    for (int i = 0; i < V; i++) 
        ver.push_back(Vertex(0, 0)); 
} 
*/

void Graph::addedge(int u, int v, int capacity) 
{ 
    // flow is initialized with 0 for all edge 
    //cout << edge.size() << endl;
    edge.push_back(Edge(0, capacity, u, v)); 
} 

  
void Graph::preflow(int s) 
{ 
    // Making h of source Vertex equal to no. of vertices 
    // Height of other vertices is 0. 
    ver[s].h = ver.size(); 
    
    // 
    for (int i = 0; i < edge.size(); i++) 
    { 
        //cout << i << ", " << edge.size() << endl;
        // If current edge goes from source 
        if (edge[i].u == s) 
        { 
            //cout << "here" << endl;
            // Flow is equal to capacity 
            edge[i].flow = edge[i].capacity; 
  
            // Initialize excess flow for adjacent v 
            ver[edge[i].v].e_flow += edge[i].flow; 
  
            // Add an edge from v to s in residual graph with 
            // capacity equal to 0 
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s)); 
        } 
    } 
    
} 
  
// returns index of overflowing Vertex 
int overFlowVertex(vector<Vertex>& ver) 
{ 
    for (int i = 1; i < ver.size() - 1; i++) 
       if (ver[i].e_flow > 0) 
            return i; 
  
    // -1 if no overflowing Vertex 
    return -1; 
} 
  
// Update reverse flow for flow added on ith Edge 
void Graph::updateReverseEdgeFlow(int i, int flow) 
{ 
    int u = edge[i].v, v = edge[i].u; 
  
    for (int j = 0; j < edge.size(); j++) 
    { 
        if (edge[j].v == v && edge[j].u == u) 
        { 
            edge[j].flow -= flow; 
            return; 
        } 
    } 
  
    // adding reverse Edge in residual graph 
    Edge e = Edge(0, flow, u, v); 
    edge.push_back(e); 
} 
  
// To push flow from overflowing vertex u 
bool Graph::push(int u) 
{ 
    // Traverse through all edges to find an adjacent (of u) 
    // to which flow can be pushed 
    for (int i = 0; i < edge.size(); i++) 
    { 
        // Checks u of current edge is same as given 
        // overflowing vertex 
        if (edge[i].u == u) 
        { 
            // if flow is equal to capacity then no push 
            // is possible 
            if (edge[i].flow == edge[i].capacity) 
                continue; 
  
            // Push is only possible if height of adjacent 
            // is smaller than height of overflowing vertex 
            if (ver[u].h > ver[edge[i].v].h) 
            { 
                // Flow to be pushed is equal to minimum of 
                // remaining flow on edge and excess flow. 
                int flow = min(edge[i].capacity - edge[i].flow, 
                               ver[u].e_flow); 
  
                // Reduce excess flow for overflowing vertex 
                ver[u].e_flow -= flow; 
  
                // Increase excess flow for adjacent 
                ver[edge[i].v].e_flow += flow; 
  
                // Add residual flow (With capacity 0 and negative 
                // flow) 
                edge[i].flow += flow; 
  
                updateReverseEdgeFlow(i, flow); 
  
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
// function to relabel vertex u 
void Graph::relabel(int u) 
{ 
    // Initialize minimum height of an adjacent 
    int mh = INT_MAX; 
  
    // Find the adjacent with minimum height 
    for (int i = 0; i < edge.size(); i++) 
    { 
        if (edge[i].u == u) 
        { 
            // if flow is equal to capacity then no 
            // relabeling 
            if (edge[i].flow == edge[i].capacity) 
                continue; 
  
            // Update minimum height 
            if (ver[edge[i].v].h < mh) 
            { 
                mh = ver[edge[i].v].h; 
  
                // updating height of u 
                ver[u].h = mh + 1; 
            } 
        } 
    } 
} 
  
// main function for printing maximum flow of graph 
int Graph::getMaxFlow(int s, int t) 
{ 
              
    preflow(s); 

    // loop until none of the Vertex is in overflow 
    while (overFlowVertex(ver) != -1) 
    { 

        int u = overFlowVertex(ver); 
        if (!push(u)) 
            relabel(u); 
    } 
  
    // ver.back() returns last Vertex, whose 
    // e_flow will be final maximum flow 
    return ver.back().e_flow; 
} 