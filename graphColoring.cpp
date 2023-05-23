
#include<bits/stdc++.h>
using namespace std;

// void init_code() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// }


bool isSafe(int node, vector<vector<int>>& graph, vector<int>& c, int ind) {
	for (int i = 0; i < graph[node].size(); ++i) {
		int u = graph[node][i];
		if (c[u] == ind) {
			return false;
		}
	}
	return true;
}


bool graphColoring(vector<vector<int>>& graph, vector<int>& c, int node, vector<string>& colors) {

	if (node == graph.size())
		return true;

	for (int i = 0; i < colors.size(); ++i) {
		if (isSafe(node, graph, c, i)) {

			c[node] = i;
			if (graphColoring(graph, c, node + 1, colors)) {
				return true;
			}
			c[node] = -1;
		}
	}
	return false;
}

void printSolution(const vector<int>& color, const vector<string>& colors) {
	cout << "Vertex\tColor\n";
	for (int i = 0; i < color.size(); ++i) {
		cout << i << "\t" << colors[color[i]] << endl;
	}
}

int main() {
//	init_code();
	int n, m;
	cout << "Enter the number of vertices and edges: ";
	cin >> n >> m;

	vector<vector<int>>graph(n);
	cout << "Enter the edges: \n";
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int k;
	cout << "Enter the number of colors: ";
	cin >> k;

	vector<string> colors(k);
	cout << "Enter the color names: ";
	for (int i = 0; i < k; ++i) {
		cin >> colors[i];
	}

	vector<int> c(graph.size(), -1);

	if (graphColoring(graph, c, 0, colors)) {
		printSolution(c, colors);
	}
	else {
		cout << "No solution exists.\n";
	}

	return 0;
}
