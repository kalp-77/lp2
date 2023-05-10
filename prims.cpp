void prims(vector<vector<pair<int, int>>>&graph, int src, int n) {
	vector<int>key(n, INT_MAX);
	vector<int>parent(n, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	key[src]  = 0;
	pq.push({0, src});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto& i : graph[u]) {
			int v = i.first;
			int wt = i.second;

			if (wt < key[v]) {
				key[v] = wt;
				parent[v] = u;
				pq.push({key[v], v});
			}
		}
	}
	for (int i = 1; i < n; i++) {
		cout << parent[i] << " - " << i << endl;
	}

}
int main() {
	init_code();
	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	vector<vector<pair<int, int>>>graph(n); // adjacency list to store graph

	for (int i = 0; i < m; i++) {
		int u, v, wt; // edge between node u and node v with weight w
		cin >> u >> v >> wt;
		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt}); // adding both ways for undirected graph
	}
	prims(graph, 0, n);
	return 0;
}
