
#include<bits/stdc++.h>
using namespace std;

//A*
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

	for (int node : path) {
		cout << node << " ";
	}
	cout << endl;
}

void fun(vector<vector<pair<int, int>>>&graph, int src, int dest, int n) {

	vector<int>dist(n + 1, INT_MAX);
	vector<int>heuristic(n + 1);
	vector<int>parent(n + 1, -1);

	dist[src] = 0;

	cout << "Enter the heuristic values for each node:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> heuristic[i];
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// {fn, node};
	pq.push({0 + heuristic[src], src});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (u == dest) break;
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first; // b
			int wt = graph[u][i].second; // 4

			int gn = dist[u] + wt;
			int hn = heuristic[v];
			int fn = gn + hn;
			if (gn < dist[v]) {
				dist[v] = gn;
				parent[v] = u;
				pq.push({fn, v});
			}
		}
	}
	if (dist[dest] != INT_MAX) {
		cout << dist[dest] << endl;
	}
	else {
		cout << "not reachable" << endl;
	}
	printpath(parent, dest);
}

int main() {
	//init_code();
	int n, m; // no. of nodes / edges
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
// input :
// 7 9
// 1 2 4
// 1 3 3
// 3 4 7
// 4 5 2
// 3 5 10
// 2 5 12
// 2 6 5
// 6 7 16
// 5 7 5
// 1 7
// 14
// 12
// 11
// 6
// 4
// 11
// 0


