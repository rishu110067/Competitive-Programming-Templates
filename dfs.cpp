vll g[N] ;
ll d[N] ;
void dfs(ll node,ll par=-1) {
	for(auto i : g[node]) {
		if(i != par) {
			d[i] = d[node] + 1;
			dfs(i,node) ;
		}
	}
}