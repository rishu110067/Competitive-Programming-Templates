vll v[mxN];
vll vis(mxN);
vll in(mxN);
bool cycle;
void cdfs(ll x)
{
    vis[x]=1;
    for(auto i:v[x])
    {
        if(vis[i]==1){ cycle=true; break; }
        if(vis[i]==0) cdfs(i);
        if(cycle) break;
    }
    vis[x]=2;
}
bool is_cycle(ll n)
{
    cycle=false;
    rep(i,1,n+1)
    {
        if(in[i]==0) cdfs(i); 
        if(cycle) break;
    }
    rep(i,1,n+1) 
        if(vis[i]==0) cycle=true;
    return cycle;
}