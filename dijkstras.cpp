#include iostream;
using namespace std;



const int INF = INT_MAX;
void printpath(vector<int>parent, int dest) {
	if (parent[dest] == -1) {
		cout << "No path from src to dest";
		return;
	}

	vector<int>path;

	for (int curr = dest; curr != -1; curr = parent[i]) {
		path.push_back(curr);
	}
	reverse(path.begin(), path.end());

	for (int node : path) {
		cout << node << " ";
	}
	cout << endl;
}
void dij(vector<vector<pair<int, int>>>& graph, int src, int dest, int n) {
	vector<int>dis(n, INF);
	vector<int>parent(n, -1);
	vector<int>vis(n, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(src);
	dist[src] = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();


		if (vis[node]) continue;
		vis[node] = true;

		for (auto i : graph[node]) {
			int child = i.first;
			int wt = i.second;
			if (dist[node] + wt < dist[child] && !vis[child]) {
				dist[child] = dist[node] + wt;
				pq.push({dist[child], wt});
				parent[child] = node;
			}
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	int src, dest;
	cin >> src >> dest;

	dij(graph, src, dest, n);

}