

template<typename flow_t = long long>
struct Dinic {
    struct FlowEdge 
    {
        int v, u;
        flow_t cap, flow = 0;
        FlowEdge(int v, int u, flow_t cap) : v(v), u(u), cap(cap) {}
    };
    const flow_t flow_inf = numeric_limits<flow_t>::max()/2;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    // s -> source
    // t -> sink
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) 
    {
        adj.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edge(int v, int u, flow_t cap) 
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() 
    {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    flow_t dfs(int v, flow_t pushed) 
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            flow_t tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    flow_t flow() 
    {
        flow_t f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (flow_t pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
// .add_edge(u,v,cap);u->v
// .flow() == maxFlow


//Use - https://www.codechef.com/viewsolution/47741478
