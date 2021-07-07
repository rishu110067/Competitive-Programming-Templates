// Find Lowest Common Ancestor (LCA) of two nodes in a tree in O(logn)

const ll N=2e5;
vll v[N];
ll par[N][20];
ll dep[N];

// find depth and parent of each node
void dfs(ll x,ll p)
{
    if(x==p) dep[x]=0;
    par[x][0]=p;
    for(auto i:v[x])
    {
        if(i==p) continue;
        dep[i]=dep[x]+1;
        dfs(i,x);
    }
}

// find parents of every node at two's power
void find_parent(ll n)
{
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= n; j++)
                par[j][i] = par[par[j][i - 1]][i - 1];
}   

// lowest comman ancestor - binary lifting
ll lca(ll u,ll v)
{
    if(dep[u] < dep[v]) swap(u, v);
    
    for(int i = 19; i >= 0; i--)
        if(dep[par[u][i]] >= dep[v])
            u = par[u][i];
    
    if(u == v) return u;
    
    for(int i = 19; i >= 0; i--)
        if(par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
            
    return par[u][0];
}        
        
// find distance between x and y if one of them is lca
ll dis(ll x,ll y)
{
    if(x==y) return 0;
    if(dep[x]<dep[y]) swap(x,y);

    ll d=0;
    for(int i=19; i>=0; i--)
        if(dep[par[x][i]]>dep[y])
            x=par[x][i], d+=(1<<i);
    d++;
    return d;
}
