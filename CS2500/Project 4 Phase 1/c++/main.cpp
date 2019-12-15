/*
* Author: Evan Wilcox
* File: main.cpp Date: 4/23/19
* Class: CS 2500 section A
* Instructor : Bruce McMillan
* Brief: File used to create a minimum spanning tree of cities in Missouri
*        from a file of cites names, latitudes, and longitudes.
*/

#include <fstream>
#include "Graph.h"

using namespace std;


int main()
{
    ifstream fin;
    fin.open("data.csv");

    //ofstream fout;
    //fout.open("out.txt");

    vector<Node> V;

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
        
        V.emplace_back(name, lat, lon);
    };

    Graph G(&V);

    float dis;

    for(int x = 0; x < V.size(); x++)
    {
        for(int y = 0; y < V.size(); y++)
        {
            dis = sqrt(pow((V[x].m_lat-V[y].m_lat), 2) + pow((V[x].m_long-V[y].m_long), 2)) * 69;

            if(dis < 50)
            {
                G.addEdge(x, y, dis);
            }
        }
    } 

    G.print();
    cout << "=============Prim's algorithm: =================" << endl;
    //G.PrimMST(0).print();
    cout << "=============Kruskal's algorithm: =================" << endl;
    //G.KruskalMST().print();

    /*
    for(int x = 0; x < adj.size(); x++)
    {
        fout << V[x].m_name << ": ";
        for(int y = 1; y < adj[x].size(); y++)
        {
            fout << V[adj[x][y].first].m_name << ", ";
        }
        fout << endl;
    }
    */


   

    fin.close();
    //fout.close();

    



    return 0;
}