set<int> vis;
queue<int> q; // {t, v}
q.push(0);

while(!q.empty()) {
	int v = q.front();
	q.pop();
	
	for (int u : adj[v]) {
		if(!vis.count(u)) {
			vis.insert(u);
			q.push(u);
		}
	}
}