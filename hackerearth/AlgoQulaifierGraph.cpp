#include <bits/stdc++.h>

 using namespace std;
 
 class Graph
 {
    int V;
    list<int>* adj;
    void DFSUtil(int v, int* visited, bool ignoreIt);
    bool *status;
    public:
        Graph(int i);
        void addEdge(int s, int d);
        void DFS(int v);
        void printStatus();
        bool getStatus(int i) {return status[i];}
 };
 
 Graph::Graph(int i) :V(i)
 {
    adj = new list<int> [V];
    status = new bool[V];
    for (int i = 0; i < V; ++i)
        status[i] = false;
 }
 
 void Graph::addEdge(int s, int d)
 {
    adj[s].push_back(d);
 }
 
 void Graph::DFS(int v)
 {
    int* visited = new int[V];
    
    for (int i = 0; i < V; ++i)
        visited[i] = 0;
    
    visited[v] = -1;
    DFSUtil(v, visited, true);
    //cout << endl;
 }

void Graph::DFSUtil(int v, int* visited, bool ignoreIt)
{
    if(!ignoreIt)
        visited[v] = 1;
    //cout << v +1 << " ";
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (!ignoreIt && visited[*it] == -1)
        {
            status[*it] = true;
        }
        
        if (visited[*it] != 1)
            DFSUtil(*it, visited, false);
    }
}

void Graph::printStatus()
{
    for (int i = 0; i < V; ++i)
        cout << status[i] << " ";
}


int main()
{
    int V, E;
    cin >> V >> E;
    Graph g(V);
    while (E--)
    {
        int s, d;
        cin >> s >> d;
        g.addEdge(s-1, d-1);
        
    }
    for (int i = 0; i < V; ++i)
        if (getStatus(i) == false)
            g.DFS(i);
        
    g.printStatus();

}