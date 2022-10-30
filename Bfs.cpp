#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
vector<int> vis(1000,0);

void bfs(int src)
{
	queue<int> q;
	int i,x;
	q.push(src);
	vis[src]=1;
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(i=0;i<adj[x].size();i++)
		{
			if(!vis[adj[x][i]]) // if not visited, visit and put them in Q
			{
				q.push(adj[x][i]);
				vis[adj[x][i]]=1;
			}
		}
	}
	return;
}

int main()
{
	int n,m,u,v,i;
	cin >> n; // No. of vertices
	cin >> m; // No. of edges
	for(i=0;i<m;i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1); // assuming graph is perfectly connected
}