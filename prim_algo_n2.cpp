
// MAX SPANNING TREE O(n^2) - Dense Grapgh
const ll N=5001;
int n,d;
vector<vector<int>> adj(N); // adjacency matrix of graph

struct Edge {
    int w = -INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> max_e(n);
    max_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        
        // Find highest next edge
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || max_e[j].w > max_e[v].w))
                v = j;
        }

        // MST doesn't exist
        if (max_e[v].w == INF) {
            cout << 0 << endl;
            return;
        }

        selected[v] = true;
        total_weight += max_e[v].w;

        //update min edges to other nodes
        for (int to = 0; to < n; ++to) {
            if (adj[v][to] > max_e[to].w)
                max_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}
