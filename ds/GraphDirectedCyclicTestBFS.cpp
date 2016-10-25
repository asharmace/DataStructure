#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
    private: 
        int V;
        list<int>* adj;
        bool isCyclicUtil(int s, vector<bool>& visited);
    public:
        Graph(int v): V(v), adj(new list<int>[V]) {}
        void addEdge(int s, int d) {adj[s].push_back(d);}
        bool isCyclic();
};

bool Graph::isCyclicUtil(int s, vector<bool>& visited)
{
    list<int> Queue;
    Queue.push_back(s);
    while(!Queue.empty())
    {
        int temp = Queue.front(); Queue.pop_front();
        visited[temp] = true;
        auto it = adj[temp].begin();
        for (;it != adj[temp].end(); ++it)
        {
            if (s == *it)
                return true;
                
            if( !visited[*it])
                Queue.push_back(*it);
        }
    }
    return false;
}

bool Graph::isCyclic()
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (isCyclicUtil(i, visited))
            return true;
    }

}

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
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}