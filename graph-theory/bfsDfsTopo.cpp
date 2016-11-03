#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <vector>
using namespace std;

class Graph
{
	private:
		int V;
		list <int>* adj;
		void dfsUtil(int s, vector<bool>& visited);
		void topologicalSortUtil(int s, vector<bool>& v, stack<int>& st);

	public:
		Graph(int v);
		void addEdge(int v, int u);
		void bfs(int s);
		void dfs(int s);
		void topologicalSort();

};

Graph::Graph(int v)
{
	V = v;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int u)
{
	adj[v].push_back(u);
}

void Graph::bfs(int s)
{
	vector<bool> visited(V, false);
	
	visited[s] = true;
	deque<int> q;
	q.push_back(s);

	while(!q.empty())
	{
		s = q.front(); q.pop_front();
		cout << s << " ";

		for (auto it = adj[s].begin(); it != adj[s].end(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push_back(*it);
			}
		}
	}
	cout << endl;
}

void Graph::dfs(int s)
{
	std::vector<bool> visited(V, false);
	dfsUtil(s, visited);
	cout << endl;
}

void Graph::dfsUtil(int s, vector<bool>& visited)
{
	visited[s] = true;
	cout << s << " ";

	for(auto it = adj[s].begin(); it != adj[s].end(); ++it)
		if (!visited[*it])
			dfsUtil(*it, visited);
}

void Graph::topologicalSort()
{
	std::vector<bool> visited(V, false);
	stack<int> st;

	for(int i = 0; i <V; ++i)
		if (!visited[i])
			topologicalSortUtil(i, visited, st);

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void Graph::topologicalSortUtil(int s, vector<bool>& visited, stack<int>& st)
{
	visited[s] = true;

	for(auto it = adj[s].begin(); it != adj[s].end(); ++it)
		if(!visited[*it])
			topologicalSortUtil(*it, visited, st);

	st.push(s);
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
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.bfs(2);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.dfs(2);
    cout << "Following is TopologicalSort \n";
    g.topologicalSort();
 
    return 0;
}