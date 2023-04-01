// Description: Finds topological sort order traversal for a DAG
// Time: O(n + m)
// Pasteable: FULL

#define START_INDEX 1

// Only Edges, v

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

    for (T i = START_INDEX; i < n; i++) {
        if(!vis[i]) {
            dfsTopSort(adj, vis, ts, i);
        }
    }
    reverse(ts.begin(), ts.end());
    return ts;
}

// Edges + Weights, pair<v, w>
template<typename T1, typename T2>
void dfsTopSort(vector<vector<pair<T1, T2>>>& adj, vector<bool>& vis, vector<T1>& ts, T1 v) {
    vis[v] = 1;
    for (pair<T1, T2> uw: adj[v]) {
        if (!vis[uw.first]) {
            dfsTopSort(adj, vis, ts, uw.first);
        }
    }
    ts.push_back(v);
}

template<typename T1, typename T2>
vector<T1> topSort(vector<vector<pair<T1, T2>>>& adj) {
    int n = adj.size();
    vector<bool> vis(n,0);
    vector<T1> ts;

    for (T1 i = START_INDEX; i < n; i++) {
        if(!vis[i]) {
            dfsTopSort(adj, vis, ts, i);
        }
    }
    reverse(ts.begin(), ts.end());
    return ts;
}