#include <iostream>
#include <list>
#include <map>
using namespace std;


class Graph
{
	private:
		int V;
		list<int> *adj;
		
	public:
		Graph(int v): V(v), adj(new list<int>[V]){}
		
		void addEdge(int s, int d);
		
		map<int, int> getDegree();
		
		
};

void Graph::addEdge(int s, int d)
{
	adj[s].push_back(d);
	adj[d].push_back(s);
}

map<int, int> Graph::getDegree()
{
	map<int, int> result;
	for(int i = 0; i < V; ++i)
		result.insert(make_pair(i+1, adj[i].size()));
		
	return result;
}


int main()
{
	int V, E;
    cin >>V >> E;
    Graph g(V);
    while (E--)
    {
    	int s, d;
    	cin >> s >> d;
    	g.addEdge(s-1, d-1);
    }
    cout << endl << endl;
    map<int, int> connectivity = g.getDegree();
    
    for (auto a: connectivity)
        cout << a.first << " " << a.second << endl;
    
    return 0;
}
