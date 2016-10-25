#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& G, vector<bool>& visited, vector<int>& dfsValues, int source, int dest)
{
    cout << source << " " << endl;
	visited[source] = true;
	
	for (auto it : G[source])
	{
		if (visited[it] == false)
		{
            dfsValues[source] = dfsValues[source] + 1;
            if (source == dest) return;
			dfs(G, visited, dfsValues, it, dest);
		}
	}
}

void bfs(vector<vector<int> >& G, vector<bool>& visited, vector<int>& dfsValues, int source, int dest)
{
	list<int> myQueue;
    myQueue.push_back(source);
 
     while(!myQueue.empty())
     {
        source = myQueue.front(); myQueue.pop_front();
        dfsValues[source] = dfsValues[source] + 1;
        if (source == dest) break;
        cout << source << " " ;
        visited[source] = true;
        
        for (auto it : G[source])
        {
            if (visited[it] == false)
            {
                myQueue.push_back(it);
            }
        }
     }
}

int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<vector<int> > G(N);
	
	for (int i = 0; i < N -1; ++i)
	{
		int u, v;
		cin >> 	u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
		
	}
	vector<int> dfsValues(N, 0);
	while(Q--)
	{
		int x, y, z;
		cin >> x >> y;
		if (x == 1)
		{
			cin >> z;
			vector<bool> visited (N, false);
			dfs(G, visited, dfsValues, y-1, z-1);
            cout << "here" << endl;
            for (auto a: dfsValues) cout << a << " " ;
            cout << endl;
		}
		if (x == 2)
		{
            cout << endl;
			cout << dfsValues[y-1] << endl;
            cout << endl;
		}
	}
   
    return 0;
}
