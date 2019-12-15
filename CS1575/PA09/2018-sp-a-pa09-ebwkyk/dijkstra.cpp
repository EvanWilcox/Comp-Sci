#include "Graph.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
  string input[20];
  int numLines = 0;

  while(getline(cin, input[numLines]))
  {
    numLines++;
  }

  int numNodes = input[numLines-2].length();

  Graph matrix(numNodes);


  string currency;
  float tax;

  for(int i = 1;i < numLines-2;i++)
  {
    currency = input[i].substr(0, input[i].find('(')-1);
    tax = stof(input[i].substr(input[i].find('(')+1, input[i].find(')') - input[i].find("(")-1));

    matrix.addNode(currency, tax);
  }


  for(int x = 0;x < numNodes;x++)
  {
    int index = 0;

    for(int y = 0;y < numNodes;y++)
    {
      index = input[x+1].find(',', index) + 1;
      tax = stof(input[x+1].substr(index, input[x+1].find(',', index)-index));

      matrix.addEdge(x, y, tax);
    }
  }


  string start, end;

  int one, two, three;

  start = input[numNodes+2].substr(input[numNodes+2].find("from ")+5,input[numNodes+2].find(" to") - input[numNodes+2].find("from ")+5-10-1);
  
  one = input[numNodes+2].find('?');
  two = input[numNodes+2].find(start)+start.length()+6;
  three = one - two;

  end = input[numNodes+2].substr(input[numNodes+2].find(start)+start.length()+4+1, three);
  
  matrix.dijkstra(start, end);

  return 0;
}


void Graph::dijkstra(string start, string end) const
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  unordered_map<string, float> dist;


  for(int i = 0;i < numNodes;i++)
  {
    dist[m_nodes[i].first] = INF;

    if(m_nodes[i].first == start)
    {
      pq.push(make_pair(0, i));
      dist[m_nodes[i].first] = 0;
    }
  }


  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    list<pair<int, float>>::iterator i;
    for (i = matrix[u].begin(); i != matrix[u].end(); ++i)
    {
      int v = (*i).first;
      float weight = (*i).second;
     
      if (dist[m_nodes[v].first] > dist[m_nodes[u].first] + weight)
      {
        dist[m_nodes[v].first] = dist[m_nodes[u].first] + weight;
        pq.push(make_pair(dist[m_nodes[v].first], v));
      }
    }
  }

  if(dist[end] == INF)
  {
    start += 's';
    end += 's';

    cout << "There is no path from " << start << " to " << end << endl;
  }
  else
  {
    start += 's';
    end += 's';
    
    cout << "The shortest path from " << start << " to " << end << " is: " << dist[end.substr(0, end.length()-1)] << endl;
    
  }

/*
  cout << "Vertex   Distance from Source" << endl;
  for (int i = 0; i < numNodes; ++i)
    cout << m_nodes[i].first << "\t\t, " << dist[m_nodes[i].first] << endl;
    */
}










