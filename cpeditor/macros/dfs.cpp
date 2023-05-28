set<int> vis;

void dfs(vvi& adj, int v) {
	vis.insert(v);
	
	for (int u : adj[v]) {
		if (!vis.count(u)) {
			dfs(adj, u);
		}
	}
}