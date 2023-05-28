void build_tree(vvi& adj, int v, vvi& child, vi& par, set<int>& build_vis) {
	build_vis.insert(v);
		
	for (int u : adj[v]) {
		if (!build_vis.count(u)) {
			par[u] = v;
			child[v].pb(u);
			build_tree(adj, u, child, par, build_vis);
		}
	}
}