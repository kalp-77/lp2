const int INF = INT_MAX;
int parent[10000];

void make(int v) {
	parent[v] = v;
}
int find(int v) {
	if (parent[v] == v) {
		return parent[v];
	}
	return parent[v] = find(parent[v]);
}
void unionn(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	init_code();
	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	vector<pair<int, pair<int, int>>> edges; // adjacency list to store graph

	for (int i = 0; i < m; i++) {
		int u, v, wt; // edge between node u and node v with weight w
		cin >> u >> v >> wt;
		edges.push_back({wt, {u, v}});
		edges.push_back({wt, {v, u}}); // adding both ways for undirected graph
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++) {
		make(i);
	}
	int total_cost = 0;
	for (auto &edge : edges) {
		int wt = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		if (find(u) == find(v)) continue;
		unionn(u, v);
		total_cost += wt;
		cout << u << " " << v << endl;
	}
	cout << total_cost << endl;


	return 0;
}
