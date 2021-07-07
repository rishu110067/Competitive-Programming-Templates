//Dijkstra - O(ElogV) - Weighted Graph
vpll v[mxN];
vll d(mxN,INF);
void dijk(ll src)
{
    vector<bool> vis(mxN,0);
    multiset<pll> s;
    d[src]=0;
    s.insert({0,src});
    while(!s.empty())
    {
        pll p=*s.begin();
        s.erase(s.begin());
        ll x=p.ss, wei=p.ff;
        if(vis[x]) continue;
        vis[x]=1;
        for(ll i=0; i<v[x].size(); i++)
        {
            ll e=v[x][i].ff, w=v[x][i].ss;
            if(d[x]+w<d[e])
            {
                d[e]=d[x]+w;
                s.insert({d[e],e});
            }
        }
    }
}

// BFS - O(E+V) - Unweighted Graph 
vll v[mxN];
vll d(mxN,INF);
void bfs(ll src)
{
    vector<bool> vis(mxN,0);
    queue<ll> q;
    d[src]=0;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        for(auto e:v[x])
        {
            if(d[x]+1<d[e] && !vis[e])
            {
                d[e]=d[x]+1;
                q.push(e);
                vis[e]=1;
            }
        }
    }
}

// we mark a vertex visited while pushing it into queue 
// and not while taking it out othewise it can give TLE