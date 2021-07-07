// ordered_set - PBDS
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

//s.order_of_key(k)  : Number of items strictly smaller than k 
//s.find_by_order(k) : iterator to K-th element in a set (counting from zero)
//multiset : use pair 



//Using Fenwick Tree implementing PBDS
int bit[mxN]; 
void update(ll x, ll val) {
    for (; x < mxN; x += x & -x)
        bit[x] += val;
}

ll query(ll x) {
    ll res = 0;
    for (; x > 0; x -= x & -x)
        res += bit[x];
    return res;
}

ll median(ll x)
{
    ll l=0, r=mxN-1;
    ll res=0;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(query(m)>=x) { res=m; r=m-1; }
        else l=m+1;
    }
    return res;
}