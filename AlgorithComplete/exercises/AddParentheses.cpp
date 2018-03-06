#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

bool compare(const int & a, const int & b) {
	return a < b;
}

class Solution {
public:
	
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> calculated;
		vector<int> result = computeRecurrence(input, calculated);
		sort(result.begin(), result.end(), compare);
		return result;
	}

	vector<int> computeRecurrence(string input, unordered_map<string, vector<int>> &calculated) {
		vector<int> result;

		for (int i = 0; i < input.size(); i++) {
			string leftSubquestin, rightSubquestion;
			vector<int> result1, result2;
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				leftSubquestin = input.substr(0, i);
				rightSubquestion = input.substr(i + 1);
				if (calculated.find(leftSubquestin) != calculated.end()) {
					result1 = calculated[leftSubquestin];
				}
				else {
					result1 = computeRecurrence(leftSubquestin, calculated);
				}

				if (calculated.find(rightSubquestion) != calculated.end()) {
					result2 = calculated[rightSubquestion];
				}
				else {
					result2 = computeRecurrence(rightSubquestion, calculated);
				}

				for (auto a : result1) {
					for (auto b : result2) {
						if (input[i] == '+') {
							result.push_back(a + b);
						}
						else if (input[i] == '-') {
							result.push_back(a - b);
						}
						else {
							result.push_back(a * b);
						}
					}
				}
			}
		}

		if (result.empty()) {
			result.push_back(atoi(input.c_str()));
		}

		calculated[input] = result;
	    
		return result;
	}
};

//int main() {
//	Solution s;
//	string input = "2*3-4*5";
//	vector<int> result = s.diffWaysToCompute(input);
//	for (auto a : result) {
//		cout << a << " ";
//	}
//	system("pause");
//	return 0;
//}