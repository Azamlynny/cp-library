int n;
	cin >> n;
	
	vvi adj(n);
	
	for(int i = 0; i < n - 1; i++) {
		int u,v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	// // COMMAND: treeb
	// vvi dag(n);
	// vi rev(n);
	// set<int> build_vis;
	// build_tree(adj, 1, dag, rev, build_vis);