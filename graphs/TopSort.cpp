 // Description: Finds topological sort order traversal for a DAG
 // Time: O(n + m)

// Only Edges

template<typename T>
void dfsTopSort(vector<vector<T>>& adj, vector<bool>& vis, vector<T>& ts, T v) {
    vis[v] = 1;
    for (T u : adj[v]) {
        if (!vis[u]) {
            dfsTopSort(adj, vis, ts, u);
        }
    }
    ts.push_back(v);
}

template<typename T>	
vector<T> topSort(vector<vector<T>>& adj) {
    int n = adj.size();
    vector<bool> vis(n,0);
    vector<T> ts;

    for (T i = 0; i < n; i++) {
        if(!vis[i]) {
            dfsTopSort(adj, vis, ts, i);
        }
    }
    reverse(ts.begin(), ts.end());
    return ts;
}

// Edges + Weights



