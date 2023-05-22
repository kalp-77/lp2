#include<bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

//A*
void fun(vector<vector<pair<int, int>>>&graph, int src, int dest, int n) {

	vector<int>dist(n + 1, INT_MAX);
	vector<int>k(n + 1);

	dist[src] = 0;

	cout << "Enter the heuristic values for each node:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (u == dest) break;
		for (auto i : graph[u]) {
			int v = i.first;
			int wt = i.second;

			int gn = dist[u] + wt;
			int hn = k[v];

			if (gn + hn < dist[v]) {
				dist[v] = gn;
				pq.push({gn + hn, v});
			}
		}
	}
	if (dist[dest] != INT_MAX) {
		cout << dist[dest] << endl;
	} else {
		cout << "not reachable" << endl;
	}
	for (int i = 1; i < dist.size(); i++) {
		cout << src << " to " << i << " : " << dist[i] << " : " << k[i] << endl;
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

	int src, dest;
	cin >> src >> dest;

	fun(graph, src, dest, n);

	return 0;
}

