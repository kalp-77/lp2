
vector<int>vis(100000,0);

void dfs(vector<vector<int>>& graph, int node) {
    visited[node] = 1;
    cout << node << " ";

    for (int child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, child);
        }
    }
}

void bfs(vector<vector<int>>& graph, int v) {
	queue<int> q; // Queue for BFS traversal
	vis.clear();
	q.push(v);
	vis[v] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " "; // Process the node
    
		// Explore all adjacent nodes
		for (int child : graph[node]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = 1;
			}
		}
	}
}



int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); 
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    dfs(graph, start);
  // bfs(graph, start);

    return 0;
}
