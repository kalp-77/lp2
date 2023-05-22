
#include<bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


void display(vector<vector<int>>& board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == 1) {
				cout << "Q ";
			}
			else cout << "X ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(vector<vector<int>>&board, int row, int col) {
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][col] == 1) {
			return false;
		}
	}
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 1) {
			return false;
		}
	}
	for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
		if (board[i][j] == 1) {
			return false;
		}
	}
	return true;

}


int nQueen(vector<vector<int>>& board, int row) {
	if (row == board.size()) {
		display(board);
		return 1;
	}
	int cnt = 0;
	for (int col = 0; col < board.size(); col++) {
		if (isSafe(board, row, col)) {
			board[row][col] = 1;
			cnt += nQueen(board, row + 1);
			board[row][col] = 0;
		}
	}
	return cnt;
}



int main() {
	init_code();
	int n;
	cin >> n;
	vector<vector<int>>board(n, vector<int>(n, 0));
	int ans = nQueen(board, 0);
	cout << ans << endl;
}
