#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (isFind(board, i, j, word.c_str())) {
					return true;
				}
			}
		}
		return false;
	}

	bool isFind(vector<vector<char>>& board, int i, int j, const char * word) {
		if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0
			|| board[i][j] == '\0' || board[i][j] != *word) {
			return false;
		}

		if (*(word + 1) == '\0') return true;

		char t = board[i][j];
		board[i][j] = '\0';
		if (isFind(board, i + 1, j, word + 1) || isFind(board, i - 1, j, word + 1) ||
			isFind(board, i, j + 1, word + 1) || isFind(board, i, j - 1, word + 1)) {
			return true;
		}

		board[i][j] = t;
		return false;
	}
};

//int main() {
//	vector<vector<char>> test;
//	vector<char> t1;
//	t1.push_back(char('A'));
//	t1.push_back(char('B'));
//	t1.push_back(char('C'));
//	t1.push_back(char('E'));
//	test.push_back(t1);
//
//	vector<char> t2;
//	t2.push_back(char('S'));
//	t2.push_back(char('F'));
//	t2.push_back(char('C'));
//	t2.push_back(char('S'));
//	test.push_back(t2);
//
//	vector<char> t3;
//	t3.push_back(char('A'));
//	t3.push_back(char('D'));
//	t3.push_back(char('E'));
//	t3.push_back(char('E'));
//	test.push_back(t3);
//
//	string word = "SEE";
//	Solution s;
//
//	for (int i = 0; i < test.size(); i++) {
//		for (int j = 0; j < test[0].size(); j++) {
//			cout << test[i][j] << ' ';
//		}
//	}
//	cout << endl;
//	cout << s.exist(test, word) << endl;
//	return 0;
//}