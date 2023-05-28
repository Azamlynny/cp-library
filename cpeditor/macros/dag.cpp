int n;
	cin >> n;
	
	vvi adj(n);
	
	for(int i = 0; i < n; i++) {
		ll u,v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		// adj[v].pb(u);
	}