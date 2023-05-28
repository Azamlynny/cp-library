void build_tree(vvl& adj, ll v, vvl& child, vl& par, set<ll>& build_vis) {
	build_vis.insert(v);
		
	for (ll u : adj[v]) {
		if (!build_vis.count(u)) {
			par[u] = v;
			child[v].pb(u);
			build_tree(adj, u, child, par, build_vis);
		}
	}
}