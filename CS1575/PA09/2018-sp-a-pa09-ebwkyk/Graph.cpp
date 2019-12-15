#include "Graph.h"


Graph::Graph(int size)
{
  numNodes = 0;
  
  matrix = new list<pair<int, float>>[size];

  m_nodes = new pair<string, float>[size];

}


Graph::~Graph()
{
  delete[] matrix;
  
  delete[] m_nodes;
}


void Graph::addNode(string s, float f)
{
  m_nodes[numNodes].first = s;
  m_nodes[numNodes].second = f;

  numNodes++;
}


void Graph::addEdge(int x, int y, float val)
{
  if(val != 0)
  {
    matrix[x].push_back(make_pair(y, val));
  }
}


