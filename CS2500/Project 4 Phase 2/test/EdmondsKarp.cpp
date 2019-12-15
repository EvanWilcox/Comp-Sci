/*
* Author: Evan Wilcox
* File: EdmondsKarp.cpp Date: 5/2/2019
* Class: CS 2500
* Instructor : Bruce McMillan
* Brief: Implementation file for Edmonds-Karp algorithm
*/

#include "EdmondsKarp.h"

EdmondsKarp::EdmondsKarp(int n, bool d)
{
    this->n = n;
    this->debug = d;

    capacity.resize(n);
    for(int u = 0; u < capacity.size(); u++)
    {
        capacity[u].resize(n);
    }

    adj.resize(n);
}

void EdmondsKarp::addEdge(int u, int v, int c)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = c;
}

int EdmondsKarp::bfs(int src, int end, vector<int>& parent) 
{
    fill(parent.begin(), parent.end(), -1);
    
    parent[src] = -2;
    queue<pair<int, int>> q;
    q.push({src, INF});
    
    /*
    * loop description
    * loop precondition: 
    * loop postcondition: 
    * invariant: 
    * proof: 
    *   Initialization: 
    * 
    *   Maintenance: 
    * 
    *   Termination: 
    */
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        /*
        * loop description
        * loop precondition: 
        * loop postcondition: 
        * invariant: 
        * proof: 
        *   Initialization: 
        * 
        *   Maintenance: 
        * 
        *   Termination: 
        */
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == end)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int EdmondsKarp::maxflow(int src, int end) 
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
    
    /*
    * loop description
    * loop precondition: 
    * loop postcondition: 
    * invariant: 
    * proof: 
    *   Initialization: 
    * 
    *   Maintenance: 
    * 
    *   Termination: 
    */
    while (new_flow = bfs(src, end, parent)) 
    {
        flow += new_flow;
        int cur = end;

        /*
        * loop description
        * loop precondition: 
        * loop postcondition: 
        * invariant: 
        * proof: 
        *   Initialization: 
        * 
        *   Maintenance: 
        * 
        *   Termination: 
        */
        while (cur != src) 
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}