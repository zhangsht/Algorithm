#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		for (int i = 0; i < words.size(); i++) {
			if (exist(board, words[i])) {
				ans.push_back(words[i]);
			}
		}
		return ans;
	}

	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				vector<vector<bool>> visited;
				for (int m = 0; m < board.size(); m++) {
					vector<bool> v;
					for (int n = 0; n < board[0].size(); n++) {
						v.push_back(bool(false));
					}
					visited.push_back(v);
				}

				if (isFind(board, i, j, word.c_str(), visited)) {
					return true;
				}
			}
		}
		return false;
	}

	bool isFind(vector<vector<char>>& board, int i, int j, const char * word, vector<vector<bool>> &visited) {
		if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0
			|| visited[i][j] || board[i][j] != *word) {
			return false;
		}

		if (*(word + 1) == '\0') return true;

		visited[i][j] = true;
		board[i][j] = '\0';
		if (isFind(board, i + 1, j, word + 1, visited) || isFind(board, i - 1, j, word + 1, visited) ||
			isFind(board, i, j + 1, word + 1, visited) || isFind(board, i, j - 1, word + 1, visited)) {
			return true;
		}

		visited[i][j] = false;
		return false;
	}
};
//
//int main() {
//
//	return 0;
//}