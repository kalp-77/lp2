#include<bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void prims(vector<vector<pair<int, int>>>&graph, int src, int n) {
	vector<int>parent(n + 1, -1);
	vector<int>vis(n + 1, 0);

	// {wt, node}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, src});
	int sum = 0;
	
	while (!pq.empty()) {
		int u = pq.top().second;
		int wt = pq.top().first;
		pq.pop();

		if (vis[u] == 1) continue;
		vis[u] = 1;
		sum += wt;
		cout << sum << endl;
		for (auto i : graph[u]) {
			int v = i.first;
			int edgWt = i.second;

			if (!vis[v]) {
				pq.push({edgWt, v});
				parent[v] = u;
			}
		}
	}
	cout << sum << endl;
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << " - " << i << endl;
	}

}
int main() {
	init_code();
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>>graph(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt});
	}
	int src;
	cin >> src;
	prims(graph, src, n);

}
