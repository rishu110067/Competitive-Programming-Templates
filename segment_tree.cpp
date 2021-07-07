//0-indexed
//Segment Tree for Range sum query and point update
const ll N=2e5+1;
ll seg[4*N]; 
void update(ll idx,ll val,ll nd=0,ll l=0,ll r=N-1)
{
    if(l==r){ seg[nd]=val; return; }
    
    ll m=(l+r)/2;
    ll lnd=2*nd+1;
    ll rnd=2*nd+2;
    
    if(idx<=m) update(idx,val,lnd,l,m);
    else update(idx,val,rnd,m+1,r);

    seg[nd]=seg[lnd]+seg[rnd];
}
ll query(ll L,ll R,ll nd=0,ll l=0,ll r=N-1)
{
    //for min return 1e18, for max return -1e18, for sum and gcd return 0 
    if(r<L || R<l) return 0; 
    
    ll m=(l+r)/2;
    ll lnd=2*nd+1;
    ll rnd=2*nd+2;

    if(L<=l && r<=R) return seg[nd];
    else
    {
        ll q1 = query(L,R,lnd,l,m);
        ll q2 = query(L,R,rnd,m+1,r);
        return q1+q2;
    }
}

//1 indexed
//Segment Tree for Range max query and point max update
const ll N=2e5+1;
ll seg[4*N]; 
void update(ll idx,ll val,ll nd=1,ll l=1,ll r=n)
{
    if(l==r){ seg[nd]=max(seg[nd], val); return; }
    
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;
    
    if(idx<=m) update(idx,val,lnd,l,m);
    else update(idx,val,rnd,m+1,r);

    seg[nd]=max(seg[lnd],seg[rnd]);
}
ll query(ll L,ll R,ll nd=1,ll l=1,ll r=n)
{
    if(r<L || R<l) return 0; 
    
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;

    if(L<=l && r<=R) return seg[nd];
    else
    {
        ll q1 = query(L,R,lnd,l,m);
        ll q2 = query(L,R,rnd,m+1,r);
        return max(q1,q2);
    }
}

//1-indexed
//Lazy Propgation Segment Tree for and Range min query and Range update (inc. all values in range by x)
ll n;
const ll N=2e5+1;
ll seg[4*N], upd[4*N]; 
void update(ll L,ll R,ll x,ll nd=1,ll l=1,ll r=n)
{
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;
 
    seg[nd]+=upd[nd];
    if(l!=r)
    {
        upd[lnd]+=upd[nd];
        upd[rnd]+=upd[nd];
    }
    upd[nd]=0; 
   
    if(r<L || R<l) return; 
    if(r==l)
    { 
        seg[nd]+=x; 
        return; 
    }
    if(L<=l && r<=R) 
    {
        seg[nd]+=x;
        upd[lnd]+=x; 
        upd[rnd]+=x;
    }
    else
    {
        update(L,R,x,lnd,l,m);
        update(L,R,x,rnd,m+1,r);
        seg[nd]=min(seg[lnd],seg[rnd]);
    }
}
ll query(ll L,ll R,ll nd=1,ll l=1,ll r=n)
{
    ll m=(l+r)/2, lnd=2*ndm, rnd=2*nd+1;
 
    seg[nd]+=upd[nd];
    if(l!=r)
    {
        upd[lnd]+=upd[nd];
        upd[rnd]+=upd[nd];
    }
    upd[nd]=0; 
 
    if(r<L || R<l) return 1e18; 
    if(r==l) return seg[nd]; 
    if(L<=l && r<=R) return seg[nd];
    else
    {
        ll q1=query(L,R,lnd,l,m);
        ll q2=query(L,R,rnd,m+1,r);
        seg[nd]=min(seg[lnd],seg[rnd]);
        return min(q1,q2);
    }
}

//1-indexed
//Lazy Propgation Segment Tree for and Range sum query and Range update (set all values in range to x)
const ll N=2e5+1;
ll seg[4*N], upd[4*N]; 
void update(ll L,ll R,ll x,ll nd=1,ll l=1,ll r=n)
{
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;
 
    if(upd[nd]!=0)
    {
        seg[nd]=upd[nd]*(r-l+1);
        if(l!=r)
        {
            upd[lnd]=upd[nd];
            upd[rnd]=upd[nd];
        }
        upd[nd]=0;
    } 
   
    if(r<L || R<l) return; 
    if(r==l)
    { 
        seg[nd]=x*(r-l+1); 
        return; 
    }
    if(L<=l && r<=R) 
    {
        seg[nd]=x*(r-l+1);
        upd[lnd]=x; 
        upd[rnd]=x;
    }
    else
    {
        update(L,R,x,lnd,l,m);
        update(L,R,x,rnd,m+1,r);
        seg[nd]=seg[lnd]+seg[rnd];
    }
}
ll query(ll L,ll R,ll nd=1,ll l=1,ll r=n)
{
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;
 
    if(upd[nd]!=0)
    {
        seg[nd]=upd[nd]*(r-l+1);
        if(l!=r)
        {
            upd[lnd]=upd[nd];
            upd[rnd]=upd[nd];
        }
        upd[nd]=0;
    } 
 
    if(r<L || R<l) return 0; 
    if(r==l) return seg[nd]; 
    if(L<=l && r<=R) return seg[nd];
    else
    {
        ll q1=query(L,R,lnd,l,m);
        ll q2=query(L,R,rnd,m+1,r);
        seg[nd]=seg[lnd]+seg[rnd];
        return q1+q2;
    }
}


//1-indexed
//Lazy Propgation Segment Tree for Range sum query and Range AP update (inc. all values in range by AP)
const ll N=2e5+1;
ll seg[4*N], ft[4*N], cd[4*N];
void update(ll L,ll R,ll nd=1,ll l=1,ll r=n)
{
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;

    seg[nd]+=sumAP(ft[nd],cd[nd],r-l+1);
    if(l!=r)
    {
        ft[lnd]+=ft[nd];
        cd[lnd]+=cd[nd];
        ft[rnd]+=AP(ft[nd],cd[nd],m+1-l+1);
        cd[rnd]+=cd[nd];
    }
    ft[nd]=0; cd[nd]=0;
   
    
    if(r<L || R<l) return; 
    if(r==l)
    { 
        seg[nd]+=l-L+1; 
        return; 
    }
    if(L<=l && r<=R) 
    {
        seg[nd]+=segAP(l-L+1,1,r-l+1);
        ft[lnd]+=l-L+1;
        cd[lnd]++;
        ft[rnd]+=m+1-L+1;
        cd[rnd]++;
    }
    else
    {
        update(L,R,lnd,l,m);
        update(L,R,rnd,m+1,r);
        seg[nd]=seg[lnd]+seg[rnd];
    }
}
ll query(ll L,ll R,ll nd=1,ll l=1,ll r=n)
{
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;

    seg[nd]+=segAP(ft[nd],cd[nd],r-l+1);
    if(l!=r)
    {
        ft[lnd]+=ft[nd];
        cd[lnd]+=cd[nd];
        ft[rnd]+=AP(ft[nd],cd[nd],m+1-l+1);
        cd[rnd]+=cd[nd];
    }
    ft[nd]=0; cd[nd]=0;

    if(r<L || R<l) return 0; 
    if(r==l) return seg[nd]; 
    if(L<=l && r<=R) return seg[nd];
    else
    {
        ll q1=query(L,R,lnd,l,m);
        ll q2=query(L,R,rnd,m+1,r);
        seg[nd]=seg[lnd]+seg[rnd];
        return q1+q2;
    }
}


// Problem on Lazy Propagation Segment Tree (including mx,mn,sum range queries and update) and its beautiful implementation
// https://codeforces.com/contest/1439/problem/C
// https://codeforces.com/contest/1439/submission/120268200


// https://codedrills.io/contests/amrita-icpc-practice-session-7/problems/subarray-mex-sum
// https://codedrills.io/submissions/81644