#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph
{
  private:

    int V;
    list<pair<int, float>> *adj;

  public:

    Graph(int V);

    void addEdge(int u, int v, float w);

    void shortestPath(int s, int e);
};


Graph::Graph(int V)
{
  this->V = V;
  adj = new list<pair<int, float>>[V];
}


void Graph::addEdge(int u, int v, float w)
{
  adj[u].push_back(make_pair(v, w));
  //adj[v].push_back(make_pair(u, w));
}


void Graph::shortestPath(int src, int end)
{
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

  vector<float> dist(V, INF);

  pq.push(make_pair(0, src));
  dist[src] = 0;


  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    list< pair<int, float> >::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
      int v = (*i).first;
      float weight = (*i).second;

      if (dist[v] > dist[u] + weight)
      {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  /*
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < V; ++i)
    printf("%d \t\t %g\n", i, dist[i]);
  */

  cout << "The shortest path from " << end << " to " << src << " is: " << dist[end] << endl;
}

int main()
{
  int V = 9;
  Graph g(V);

  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);
  g.addEdge(8, 1, 5);

  g.shortestPath(0, 6);

  return 0;
}




