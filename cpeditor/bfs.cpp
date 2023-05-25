set<ll> vis;
queue<pair<ll,ll>> q; // {t, v}
q.push({0,1});

while(!q.empty()) {
	ll t = q.front().first;
	ll v = q.front().second;	
	q.pop();
	
	for (ll u : adj[v]) {
		if(!vis.count(u)) {
			vis.insert(u);
			q.push({t+1,u});
		}
	}
}