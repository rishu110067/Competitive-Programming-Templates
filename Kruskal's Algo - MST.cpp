//include DSU before using it

// Kruskal's algo
vtll e;
vtll mst;
ll kruskal()
{
    sortall(e);
    ll cost=0;
    rep(i,0,n) make_set(i);
    for(auto i:e)
    {
        ll w,x,y; 
        tie(w,x,y)=i;
        if(find_set(x)!=find_set(y))
        {
            cost+=w;
            union_sets(x,y);
            mst.pb(i);
        }
    }
    return cost;
}
