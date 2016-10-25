#include <iostream>
#include <list>
#include <stack>
using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
private:
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int s, bool* visited);
    void topologicalSortUtil(int i, bool* visited, stack<int>& s);
    void printStack(stack<int>& s);
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
    void DFS(int s);  // prints DFS traversal from a given source s
    void printGraph();
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
void Graph::printGraph()
{
    for (int i = 0; i < V; ++i)
    {
        list<int>::iterator it = adj[i].begin();
        cout << "head" ; 
        for (; it != adj[i].end(); ++it)
        {
            cout << " -> " << *it ;
        }
        cout << endl << endl;
    }
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    
    for(int i = 0; i < V; ++i)
        visited[i] = false;
    
    list<int> queue;
    
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator it;
    
    while(!queue.empty())
    {
        s = queue.front();
        cout <<  s << " ";
        queue.pop_front();
        
        for(it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            if (visited[*it] == false)
            {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
    
    delete visited;
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
    
    delete visited;
}

void Graph::DFSUtil(int v, bool* visited)
{
    visited[v] = true;
    cout << v << " ";
    
    list<int>::iterator it = adj[v].begin();
    for (; it != adj[v].end(); ++it)
    {
        if (!visited[*it])
            DFSUtil(*it, visited);
    }
}

void Graph::topologicalSort()
{
    stack<int>s;
    
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
    {
        visited[i] = false; 
    }
   
    for (int i = 0; i < V; ++i)
    {
        // if (!visited[i])
            topologicalSortUtil(i, visited, s);
    }
    printStack(s);
    delete visited;
}

void Graph::topologicalSortUtil(int i, bool* visited, stack<int>& s)
{
    if (visited[i]) return;
    visited[i] = true;
    list<int> :: iterator it;
    for (it = adj[i].begin(); it != adj[i].end(); ++it)
    {
        if (visited[*it] == false)
        {
            // visited[*it] = true;
            topologicalSortUtil(*it, visited, s);
        }
    }
    s.push(i);
}

void Graph::printStack(stack<int>& s)
{
    while (!s.empty())
    {
        cout << s.top() << "  ";
        s.pop();
    }
}

int main()
{
    // create the graph given in above fugure
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    // print the adjacency list representation of the above graph
    g.printGraph();
    g.BFS(2);
    cout << endl;
    g.DFS(2);
    cout << endl;
    g.topologicalSort();
    return 0;
    
}