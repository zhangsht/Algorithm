#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int row = board.size();
		if (!row) return;
		int col = board[0].size();
		for (int i = 0; i < row; i++) {
			check(board, i, 0);
			if (col > 1) check(board, i, col - 1);
		}
		for (int j = 1; j + 1 < col; j++) {
			check(board, 0, j);
			if (row > 1) check(board, row - 1, j);
		}

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (board[i][j] == 'O')
					board[i][j] = 'X';
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (board[i][j] == '1')
					board[i][j] = 'O';
	}

	void check(vector<vector<char>>& board, int i, int j) {
		int row = board.size();
		int col = board[0].size();

		if (board[i][j] == 'O') {
			board[i][j] = '1';
			if (i < row - 1)
				check(board, i + 1, j);
			if (i > 1)
				check(board, i - 1, j);
			if (j < col - 1)
				check(board, i, j + 1);
			if (j > 1)
				check(board, i, j - 1);
		}
	}
};

//int main() {
//	Solution s;
//	vector<vector<char>> v;
//	s.solve(v);
//	return 0;
//}