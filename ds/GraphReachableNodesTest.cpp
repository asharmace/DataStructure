#include <iostream>
#include <deque>
#include <list>
#include <vector>

using namespace std;

class Graph
{
    private: 
        int V;
        list<int>* adj;
    public:
        Graph(int v): V(v), adj(new list<int>[V]) {}
        void addEdge(int s, int d) {adj[s].push_back(d);}
        bool isReachable(int s, int d);
};

bool Graph::isReachable(int s, int d)
{
    vector<bool> visited(V, false);
    list<int> Queue;
    Queue.push_back(s);
    while(!Queue.empty())
    {
        s = Queue.front(); Queue.pop_front();
        visited[s] = true;
        auto it = adj[s].begin();
        for (;it != adj[s].end(); ++it)
        {
            if (d == *it)
                return true;
                
            if( !visited[*it])
                Queue.push_back(*it);
        }
    }
    return false;
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;
}