#include<bits/stdc++.h>
using namespace std;



void printPath(vector<vector<pair<int,int>>>&graph, vector<int>&parent, int dest) {

    if(parent[dest] == -1) {
        cout<<"no path exist";
    }
    vector<int>path;
    for(int curr = dest; curr!=-1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    for(auto i: path) {
        cout<<i <<" ";
    }
    cout<<endl;
}
void dij(vector<vector<pair<int,int>>>& graph, int src, int dest, int n) {
    vector<int>dist(n+1, INT_MAX);
    vector<int>parent(n+1, -1);
    vector<int>vis(n+1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i].first;
            int wt = graph[u][i].second;

            if(dist[u] + wt < dist[v] && !vis[v]){
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    printPath(graph, parent, dest);
    int cost = 0;
    cout << "Minimum cost from source to each vertex:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ": ";
        if (dist[i] != INT_MAX){
            cost+=dist[i];
            cout << dist[i] << endl;
        }
        else cout << "Not reachable" << endl;
    }
    cout<<"minimum cost from src to dest : " << dist[dest]<<endl;
}
int main() {

    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0; i<m; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    int src,dest;
    cin>>src>>dest;
    dij(graph, src, dest, n);

    return 0;
}

// input: 
// 6 10
// 1 2 9
// 1 3 4
// 2 3 2
// 3 4 1
// 3 5 6
// 2 4 7
// 2 5 3
// 4 5 4
// 4 6 8
// 5 6 2
// 1 6
