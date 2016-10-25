//#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
    private :
        int V;
        list<int>* adj;
        bool isCyclicUtil(vector<bool>& visited, vector<bool>& recStack, int n);
        
    public:
        Graph(int v) : V(v), adj(new list<int>[v]) {}
        void addEdge(int s, int d) { adj[s].push_back(d);}
        bool isCyclic();

};

bool Graph::isCyclic()
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    
    bool result = false;
    
    for(int i = 0; i < V; i++)
    {
        if (isCyclicUtil(visited, recStack, i))
        {
            result = true;
            break;
        }
    }
    return result;
}

bool Graph::isCyclicUtil(vector<bool>& visited, vector<bool>& recStack, int n)
{
    if (!visited[n])
    {
        recStack[n] = true;
        visited[n] = true;
        
        for(auto it = adj[n].begin(); it != adj[n].end(); ++it)
        {
            if (visited[*it] && isCyclicUtil(visited, recStack, *it))
                return true;
            else if (recStack[*it])
                return true;
        }
    }
    recStack[n] = false;
    return false;
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