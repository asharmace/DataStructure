#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Graph
{
    private:
        int V;
        list<int>* adj;
        void topologicalSortUtil(int v, bool* visited, stack<int>& s);
    public:
        Graph(int v);
        void addEdge(int s, int d);
        void topologicalSort();
};

Graph::Graph(int v): V(v)
{
    adj = new list<int>[V];
}

void Graph::addEdge(int s, int d)
{
    adj[s-1].push_back(d-1);
}

void Graph::topologicalSort()
{
    bool* visited = new bool[V];
    
    for(int i = 0; i < V; ++i)
        visited[i] = false;
        
     stack<int> s;
     
     for (int i = 0; i < V ; ++i)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, s);
            
     while (!s.empty())
     {
        cout << s.top() << " " ;
        s.pop();
     }
     cout << endl;
}

void Graph::topologicalSortUtil(int v, bool* visited, stack<int>& s)
{
    visited[v] = true;
    list<int>::iterator it;
    
    for(it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if(visited[*it] == false)
            topologicalSortUtil(*it, visited, s);
    }
    s.push(v+1);
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(9);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(5, 6);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
 
    return 0;
}