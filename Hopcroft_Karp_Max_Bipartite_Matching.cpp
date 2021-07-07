// Hopcroft Karp algorithm for 
// Maximum Bipartite Matching

#define NIL 0
#define INF INT_MAX

class BipGraph
{
	int m, n;
	list<int> *adj;
	int *pairU, *pairV, *dist;

    public:
	BipGraph(int m, int n); 
	void addEdge(int u, int v); 

	bool bfs();
	bool dfs(int u);
	vector<int> hopcroftKarp();
};

vector<int> BipGraph::hopcroftKarp()
{
	pairU = new int[m+1];
	pairV = new int[n+1];
	dist = new int[m+1];

	for (int u=0; u<=m; u++)
		pairU[u] = NIL;
	for (int v=0; v<=n; v++)
		pairV[v] = NIL;

	int result = 0;
	while (bfs())
	{
		for (int u=1; u<=m; u++)
			if (pairU[u]==NIL && dfs(u))
				result++;
	}
	
    vector<int> ans(m);
    for(int i=0; i<m; i++)
        ans[i]=pairU[i+1];
    
    return ans;
}

// Returns true if there is an augmenting path
bool BipGraph::bfs()
{
	queue<int> Q;
	for (int u=1; u<=m; u++)
	{
		if (pairU[u]==NIL)
		{
			dist[u] = 0;
			Q.push(u);
        }
		else dist[u] = INF;
	}

	dist[NIL] = INF;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (dist[NIL]!=INF) break;
		for (auto v: adj[u])
		{
			if (dist[pairV[v]] == INF)
			{
				dist[pairV[v]] = dist[u] + 1;
				Q.push(pairV[v]);
			}
		}
	}

	return (dist[NIL] != INF);
}

// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u)
{
	if (u == NIL) return true;
	for (auto v: adj[u])
	{
		if (dist[pairV[v]] == dist[u]+1)
		{
			if (dfs(pairV[v]) == true)
			{
				pairV[v] = u;
				pairU[u] = v;
				return true;
			}
		}
	}
	dist[u] = INF;
	return false;
}

// Constructor
BipGraph::BipGraph(int m, int n)
{
	this->m = m;
	this->n = n;
	adj = new list<int>[m+1];
}

// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
	adj[u].push_back(v); 
}
