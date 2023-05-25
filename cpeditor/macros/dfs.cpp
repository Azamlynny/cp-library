set<ll> vis;

void dfs(vvl& adj, ll v) {
	vis.insert(v);
	
	for (ll u : adj[v]) {
		if (!vis.count(u)) {
			dfs(adj, u);
		}
	}
}