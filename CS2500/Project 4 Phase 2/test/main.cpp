/*
* Author: Evan Wilcox
* File: main.cpp Date: 5/2/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: program used to test and time three max flow algorithms
*/

#include "EdmondsKarp.h"
#include "PushRelabel.h"
#include "RelabelFront.h"
#include "FlowNetwork.h"
#include "City.h"
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

// Driver program to test above functions 
int main() 
{ 
    ifstream fin;
    fin.open("data.csv");

    vector<City> C;
    string name;
    float lat;
    float lon;

    // Input cites names and coordinates and put them in a vector V of Nodes.
    string line;
    while(getline(fin, line))
    {
        name = line.substr(0, line.find(','));
        lat = stof(line.substr(line.find(',')+1, 10));
        lon = stof(line.substr(line.find_last_of(',')+1, 10));
        
        C.emplace_back(name, lat, lon);
    };
    
    int end = 781;      // St. Louis
    int src = 448;      // Joplin
    PushRelabel<int> pr(C.size());

    vector<vector<int>> cap(C.size());
    for(int i = 0; i < C.size(); i++)
    {
        cap[i].resize(C.size());
    }

    EdmondsKarp ek(C.size(), false);
    
    float dis;

    for(int x = 0; x < C.size(); x++)
    {
        for(int y = 0; y < C.size(); y++)
        {
            dis = sqrt(pow((C[x].m_lat-C[y].m_lat), 2) + pow((C[x].m_lon-C[y].m_lon), 2)) * 69;

            if(dis < 24)
            {
                pr.AddEdge(x, y, 1);
                ek.addEdge(x, y, 1);
                cap[x][y] = 1;

            }
        }
    } 

    clock_t t;
    cout << C[src].m_name << ", " << C[end].m_name << endl;
    t = clock();
    ek.maxflow(src, end);
    cout << "Edmonds-Karp: " << (float)(clock() - t)/CLOCKS_PER_SEC << endl;
    
    t = clock();
    pr.GetMaxFlow(src, end);
    cout << "Push Relabel: " << (float)(clock() - t)/CLOCKS_PER_SEC << endl;

    t = clock();
    FlowNetwork fw(C.size(), src, end, cap);
    RelabelToFront rf(&fw);
    rf.getMaxFlow();
    cout << "Relabel to Front: " << (float)(clock() - t)/CLOCKS_PER_SEC << endl;

    return 0; 
} 