void aStar(vector<vector<pair<int, int>>>& graph, int src, int dest, int n) {
	vector<int>dist(n, INT_MAX);
	vector<int>heuristic(n, INT_MAX);

	dist[src] = 0;
	heuristic[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> pq;
	pq.push({0, src});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (u == dest) {
			break;
		}

		for (auto i : graph[u]) {
			int v = i.first;
			int wt = i.second;

			int gn = dist[u] + wt;
			int hn = heuristic[u] + heuristic[v];

			if (gn < dist[v]) {
				dist[v] = gn;
				heuristic[v] = hn;
				pq.push({dist[v] + heuristic[v], v});
			}
		}
	}
	cout << "Shortest path from " << src << " to " << dest << ": ";
	if (dist[dest] != INT_MAX) {
		cout << dist[dest] << endl;
	} else {
		cout << "not reachable" << endl;
	}
	for (int i = 0; i < dist.size(); i++) {
		cout << src << " to " << i << " : " << dist[i] << endl;
	}
}

int main() {
	init_code();
	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;
	int src, dest;
	cin >> src >> dest;

	vector<vector<pair<int, int>>>graph(n); // adjacency list to store graph

	for (int i = 0; i < m; i++) {
		int u, v, wt; // edge between node u and node v with weight w
		cin >> u >> v >> wt;
		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt}); // adding both ways for undirected graph
	}
	aStar(graph, src, dest, n);
	return 0;
}
