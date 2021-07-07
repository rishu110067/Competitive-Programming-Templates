
//Fenwick Tree - range query sum and point update increase
const ll N=1e6;
ll bit[N]; 
void update(ll x, ll val) {
    for (; x < N; x += x & -x)
        bit[x] += val;
}
ll query(ll x) {
    ll res = 0;
    for (; x > 0; x -= x & -x)
        res += bit[x];
    return res;
}