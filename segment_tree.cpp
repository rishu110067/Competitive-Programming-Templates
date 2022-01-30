//0-indexed
//Segment Tree for Range sum query and point update
const ll N = 2e5+1;
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
//Segment Tree for Range max query and point update
const ll N = 2e5+1;
vll seg(4*N,-1e18); 
void update(ll idx,ll val,ll nd=1,ll l=1,ll r=n)
{
    if(l==r){ seg[nd]=val; return; }
    
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;
    
    if(idx<=m) update(idx,val,lnd,l,m);
    else update(idx,val,rnd,m+1,r);

    seg[nd]=max(seg[lnd],seg[rnd]);
}
ll query(ll L,ll R,ll nd=1,ll l=1,ll r=n)
{
    if(r<L || R<l) return -1e18; 
    
    ll m=(l+r)/2, lnd=2*nd, rnd=2*nd+1;

    if(L<=l && r<=R) return seg[nd];
    else
    {
        ll q1 = query(L,R,lnd,l,m);
        ll q2 = query(L,R,rnd,m+1,r);
        return max(q1,q2);
    }
}

// 0 indexed
//Segment Tree for Range max query and point update
//It also returns the index where max is present
const ll N = 2e5+1;
ll n;
vll seg(4*N,-INF);
vll segi(4*N,-1);

void update(ll idx,ll val,ll nd=0,ll l=0,ll r=n-1)
{
    if(l==r)
    {
        seg[nd]=val; segi[nd]=idx;
        return;
    }

    ll m=(l+r)/2, lnd=2*nd+1, rnd=2*nd+2;
    
    if(idx<=m) update(idx,val,lnd,l,m);
    else update(idx,val,rnd,m+1,r);
    
    if(seg[lnd]>=seg[rnd])
        seg[nd]=seg[lnd], segi[nd]=segi[lnd];
    else
        seg[nd]=seg[rnd], segi[nd]=segi[rnd];
}

pll query(ll L,ll R,ll nd=0,ll l=0,ll r=n-1)
{
    if(r<L || R<l)
    {
        pll p={-INF,-1};
        return p;
    }

    ll m=(l+r)/2, lnd=2*nd+1, rnd=2*nd+2;
    
    if(L<=l && r<=R)
    {
        pll p={seg[nd],segi[nd]};
        return p;
    }
    else
    {
        pll p1=query(L,R,lnd,l,m);
        pll p2=query(L,R,rnd,m+1,r);
        
        pll p;
        if(p1.ff>=p2.ff) p=p1;
        else p=p2;
        return p;
    }
}


// Implementing Segment Tree using struct
// 0 indexed
// SEGMENT TREE FOR MAX SUFFIX AND PREFIX
template <typename T>
struct SEGTREE {

    struct NODE { 
        T sum;
        T pre;
        T suf;
    };  

    NODE merge(const NODE &A,const NODE &B) {
        NODE C;
        C.sum = A.sum + B.sum;
        C.pre = max(A.pre, A.sum + B.pre);
        C.suf = max(B.suf, B.sum + A.suf);
        return C;
    }

    vector<NODE> t, a;
    int n;
    
    void init(vector<T> A) { 
        n = A.size();
        t.resize(4 * n);
        for (auto it : A) 
            a.push_back(NODE{it, it, it});
        build(0, 0, n - 1);     
    }

    void build(int u, int tl, int tr) {
        if (tl == tr) {
            t[u] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(2 * u + 1, tl, tm);
        build(2 * u + 2, tm + 1, tr);
        t[u] = merge(t[2 * u + 1], t[2 * u + 2]);
    }

    NODE query(int l, int r) {
        if (l > r) return NODE{0, 0, 0};
        return _query(0, 0, n - 1, l, r);
    }

    NODE _query(int u, int tl, int tr, int l, int r) {
        if (tl == l && tr == r)
            return t[u];
        int tm = (tl + tr) >> 1;
        if(r <= tm) return _query(2 * u + 1, tl, tm, l, r);
        else if(l > tm) return _query(2 * u + 2, tm + 1, tr, l, r);
        else return merge(_query(2 * u + 1, tl, tm, l, tm), _query(2 *u + 2, tm + 1, tr, tm + 1, r));
    }
};


// Segment Tree for finding a subsegment a[l' ... r'] with maximal sum such that l <= l' and r' <= r
struct Data {
    ll sum, pref, suff, ans;
};
vector<Data> t(mxN);

Data combine(Data l, Data r) {
    Data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

Data make_Data(ll val) {
    Data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0ll, val);
    return res;
}

void build(vll &a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_Data(a[tl]);
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = make_Data(new_val);
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

Data query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return make_Data(0);
    if (l == tl && r == tr) 
        return t[v];
    ll tm = (tl + tr) / 2;
    Data q1 = query(v*2, tl, tm, l, min(r, tm));
    Data q2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return combine(q1, q2);
}

