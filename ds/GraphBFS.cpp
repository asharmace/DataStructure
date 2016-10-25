#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    
public:
    Graph(int i);
    void addEdge(int src, int dest);
    void BFS(int v);
};

Graph::Graph(int i): V(i)
{
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest)
{
    adj[src].push_back(dest);
}

void Graph::BFS(int v)
{
    bool* visited = new bool[V];
    
    for(int i = 0; i < V; ++i)
        visited[i] = false;
      
     list<int> myQueue;

     myQueue.push_back(v);
    
    list<int>::iterator it;
     
     while(!myQueue.empty())
     {
        v = myQueue.front();
        cout << v << " " ;
        myQueue.pop_front();
        visited[v] = true;
        
        for (it = adj[v].begin(); it != adj[v].end(); ++it)
        {
            if (visited[*it] == false)
            {
                myQueue.push_back(*it);
            }
        }
     }
        
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
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}