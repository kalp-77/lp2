
#include<bits/stdc++.h>
using namespace std;

// void init_code() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// }


const int INF = INT_MAX;
void printpath(vector<int>parent, int dest) {
	if (parent[dest] == -1) {
		cout << "No path from src to dest";
		return;
	}
	vector<int>path;
	for (int curr = dest; curr != -1; curr = parent[curr]) {
		path.push_back(curr);
	}
	reverse(path.begin(), path.end());

	cout << "Shortest Path : ";
	for (int node : path) {
		cout << node << " ";
	}
	cout << endl;
}

void dij(vector<vector<pair<int, int>>>& graph, int src, int dest, int n) {
	vector<int>dist(n + 1, INF);
	vector<int>parent(n + 1, -1);
	vector<int>vis(n + 1, 0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// {wt, node}
	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();

		if (vis[node]) continue;
		vis[node] = 1;

		for (int i = 0; i < graph[node].size(); i++) {

			int child = graph[node][i].first;
			int wt = graph[node][i].second;

			if (dist[node] + wt < dist[child] && !vis[child]) {
				dist[child] = dist[node] + wt;
				pq.push({dist[child], child});
				parent[child] = node;
			}
		}
	}
	printpath(parent, dest);

}

int main() {
	//init_code();
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt});
	}

	int src, dest;
	cin >> src >> dest;

	dij(graph, src, dest, n);

	return 0;
}
