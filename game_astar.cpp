#include<bits/stdc++.h>
using namespace std;

int heuristic(int currRow, int currCol, int goalRow, int goalCol) {
    return abs(currRow - goalRow) + abs(currCol - goalCol);
}
void aStar(vector<vector<int>>&grid, pair<int,int>& start, pair<int,int>& goal) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    // vector of vector of pair to store the parent of each cell
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));


    // priority queue to select the cell with the minimmum fn value;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    vis[start.first][start.second] = true;
    pq.push({0, start});

    // array to store the row and col offset for adjacent cells
    int dx[4] = {-1, 0, 1, 0}; // left - up - right - bottom
    int dy[4] = {0, 1, 0, -1};

    while(!pq.empty()) {

        // get the cell with minimum f value from the priority queue
        pair<int,int> current = pq.top().second;
        pq.pop();

        // check if current cell is goal node or not
        if(current == goal) {
            cout<<"reached goal"<<endl;
            // Trace back the path from the goal cell to the start cell
            vector<pair<int, int>> path;
            pair<int, int> cell = goal;

            while (cell != start) {
                path.push_back(cell);
                cell = parent[cell.first][cell.second];
            }

            path.push_back(start);

            // Print the path
            cout << "Path from start to goal:" << endl;
            for (int i = path.size()- 1; i >= 0; i--) {
                cout << "(" << path[i].first << ", " << path[i].second << ")" << endl;
            }

            return;
        }

        // explore adjacent cells
        for(int i=0; i<4; i++) {
            int adjRow = current.first + dx[i];
            int adjCol = current.second + dy[i];

            // within the boundries of the grid
            if(adjRow >= 0 && adjRow < n && adjCol >=0 && adjCol < m && !vis[adjRow][adjCol] && grid[adjRow][adjCol] != 0) {
                int gn = grid[current.first][current.second] + grid[adjRow][adjCol];
                int hn = heuristic(adjRow, adjCol, goal.first, goal.second);
                int fn = gn + hn;
                
                pq.push({fn, {adjRow, adjCol}});
                vis[adjRow][adjCol] = true;
                parent[adjRow][adjCol] = current;
            }
        }
        // explore
    }
    cout<<"Goal node is unreachable"<<endl;

}
int main() {

    int n,m;
    cin>>n>>m;


    vector<vector<int>>grid(n, vector<int>(m,0));
    cout<<"Enter 0 for blocked cells, and positive value for cells cost : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j]; 
        }
    }
    int startRow, startCol, goalRow, goalCol;
    cin>>startRow>>startCol;
    cin>>goalRow>>goalCol;

    pair<int,int> start = {startRow, startCol};
    pair<int,int> goal = {goalRow, goalCol};


    aStar(grid, start, goal);

    return 0;
}

// 5 5
// Enter 0 for blocked cells, and positive value for cells cost : 
// 1 2 3 4 5
// 0 0 1 0 1
// 2 3 4 5 6
// 0 1 0 0 1
// 1 0 1 0 1
// 0 0
// 2 4
// reached goal
// Path from start to goal:
// (0, 0)
// (0, 1)
// (0, 2)
// (1, 2)
// (2, 2)
// (2, 3)
// (2, 4)
