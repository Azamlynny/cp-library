int n;
	cin >> n;
	
	vvl adj(n+1);
	
	for(int i = 0; i < n; i++) {
		ll u,v;
		cin >> u >> v;
		adj[u].pb(v);
		// adj[v].pb(u);
	}