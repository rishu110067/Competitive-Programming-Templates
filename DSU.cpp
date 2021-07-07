//to get number of different sets - count 1 in siz or siz.size()
//clear parent and siz after DSU is used

//Disjoint Set Union
ll parent[mxN]; //map<ll,ll> parent;
ll siz[mxN];    //map<ll,ll> siz;
void make_set(ll v) {
    parent[v]=v; siz[v]=1;
}
ll find_set(ll v) {
    return (v==parent[v])?v:parent[v]=find_set(parent[v]);
}
void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if(siz[a]<siz[b]) swap(a,b);
    parent[b] = a;
    siz[a]+=siz[b]; 
    siz[b]=0; //siz.erase(b);
}
ll get_size(ll v){
    return siz[find_set(v)];
}