 #include <iostream>
 #include <list>
 #include <stack>
 
 using namespace std;
 
 class Graph
 {
    int V;
    list<int>* adj;
    void DFSUtil(int v, bool* visited);
    
    public:
        Graph(int i);
        void addEdge(int s, int d);
        void DFS(int v);
 };
 
 Graph::Graph(int i) :V(i)
 {
    adj = new list<int> [V];
 }
 
 void Graph::addEdge(int s, int d)
 {
    adj[s].push_back(d);
 }
 
 void Graph::DFS(int v)
 {
    bool* visited = new bool[V];
    
    for (int i = 0; i < V; ++i)
        visited[i] = false;
        
    DFSUtil(v, visited);
 }

void Graph::DFSUtil(int v, bool* visited)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (visited[*it] == false)
            DFSUtil(*it, visited);
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
    g.DFS(2);
 
    return 0;
}