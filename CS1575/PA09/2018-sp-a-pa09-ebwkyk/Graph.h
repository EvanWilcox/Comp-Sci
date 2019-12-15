// Graph clsss

#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>

using std::string;
using std::unordered_map;
using std::priority_queue;
using std::list;
using std::pair;
using std::vector;
using std::greater;
using std::make_pair;

// Define Infinity
#define INF 0x3f3f3f3f

class Graph
{
  private:
    list<pair<int, float>> *matrix;
    pair<string, float> *m_nodes;
    int numNodes;

  public:

    Graph(int size);
    
    ~Graph();
    
    void addNode(string s, float f);
    
    void addEdge(int x, int y, float val);
    
    void dijkstra(string a, string b) const;
};
