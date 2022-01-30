const ll K = 21;
vector<vll> SA(mxN,vector<ll>(K));
vll P(K);
vll Suffix_Array(string s)
{
    ll n = s.size();
    P[0] = 1;
    rep(i,1,K) P[i] = 2 * P[i-1];
    rep(i,0,n) SA[i][0] = s[i] - 'a';

    vector<pair<pll,ll>> v(n);
    rep(k,1,K)
    {
        rep(i,0,n)
        {
            v[i].ff.ff = SA[i][k-1];
            v[i].ff.ss = (i + P[k-1] < n)? SA[i + P[k-1]][k-1] : -1;
            v[i].ss = i; 
        }
        sortall(v);

        rep(i,0,n) 
        {
            if(i > 0 && v[i].ff == v[i-1].ff) 
                SA[v[i].ss][k] = SA[v[i-1].ss][k];
            else 
                SA[v[i].ss][k] = i;
        }
    }

    vll sa(n);
    rep(i,0,n) sa[SA[i][K-1]] = i;
    return sa;
}

// Finds Longest Common Prefix of 2 suffixes of string starting at indices i and j using Suffix Array in O(logn) time.
ll LCP(ll i, ll j, ll n)
{
    if(i == j) return n - i;
    ll len = 0;
    rrep(k,K-1,0)
    {
        if(SA[i][k] == SA[j][k])
        {
            len += P[k];
            i += P[k];
            j += P[k];
        }
    }
    return len;
}
