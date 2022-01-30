// strictly increasing - use lower_bound
// increasing or non decreasing - use upper_bound


ll LIS(vll &a)
{
    ll n=a.size();
    vll d(n+1,INF);
    d[0]=-INF;
    rep(i,0,n)
    {
        ll j=ub(all(d),a[i])-d.begin();
        // if(d[j-1]<a[i] && a[i]<d[j]) 
            d[j]=a[i];
    }
    ll len=0;
    rep(i,1,n+1) if(d[i]<INF) len=i;
    return len;
}
