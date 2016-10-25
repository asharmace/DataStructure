#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    public:
        Graph(int v);
        ~Graph();
        void addEdge(int src, int dest);
        void BFS(int v);
        void DFS(int v);
        void topologicalSort();
        
    private:
    
        int V;
        list<int>* adj;
        void DFSUtil(int v, bool* visited);
        void topologicalSortUtil(int v, bool* visited, stack<int> &s);
        
        
};

Graph::Graph(int v) : V(v)
{
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete adj;
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
    
    list<int> vQueue;
    list<int>::iterator it;
    
    vQueue.push_back(v);
    
    while(!vQueue.empty())
    {
        v = vQueue.front();
        vQueue.pop_front();
        
        cout << v << " ";
        for(it = adj[v].begin(); it != adj[v].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                vQueue.push_back(*it);
            }
        }
    }
    
    cout << endl;
    delete visited;
}

void Graph::DFS(int v)
{
    bool* visited = new bool[V];
    
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    
    DFSUtil(v, visited);
    
    cout << endl;
    delete visited;
}

void Graph::DFSUtil(int v, bool* visited)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator it = adj[v].begin();
    for(;it != adj[v].end(); ++it)
    {
        if (!visited[*it])
            DFSUtil(*it, visited);
    }
}

void Graph::topologicalSort()
{
    stack<int> s;
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    
    for (int i = 0 ; i < V; ++i)
        if (!visited[i])
            topologicalSortUtil(i, visited, s);
        
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    delete visited;
}

void Graph::topologicalSortUtil(int v, bool* visited, stack<int>& s)
{
    visited[v] = true;
    
    list<int>::iterator it = adj[v].begin();
    
    for (; it != adj[v].end(); ++it)
    {
        if (!visited[*it])
        {
            topologicalSortUtil(*it, visited, s);
        }
    }
    s.push(v);
}

int main()
{
    
    // Graph g(5);
    
    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(1,2);
    // g.addEdge(2,1);
    // g.addEdge(2,3);
    // g.addEdge(2,4);
    // g.addEdge(3,1);
    // g.addEdge(3,4);
    // g.addEdge(4,0);
    // g.addEdge(4,1);
    
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    
    g.BFS(2);
    g.DFS(2);

    g.topologicalSort();
    
}