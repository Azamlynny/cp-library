int n;
	cin >> n;
	
	vvl adj(n+1);
	
	for(int i = 0; i < n - 1; i++) {
		ll u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	// // COMMAND: treeb
	// vvl dag(n+1);
	// vl rev(n+1);
	// set<ll> build_vis;
	// build_tree(adj, 1, dag, rev, build_vis);