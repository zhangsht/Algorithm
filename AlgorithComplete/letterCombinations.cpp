#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
        	return result;
		}
		
		static const string v[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		result.push_back("");
		for (int i = 0; i < digits.size(); i++) {
			int index = digits[i] - '0';
			if (index > 9 || index < 0) {
				break;
			}
			
			if (index < 2) {
				continue;
			}
			
			vector<string> tmp;
			for (int j = 0; j < v[index].size(); j++) {
				for (int k = 0; k < result.size(); k++) {
					tmp.push_back(result[k] + v[index][j]);
				}
			}
			
			result.swap(tmp);
		}
		
		return result;
    }
};

int main() {
	Solution solution;
	cout << solution.letterCombinations("23").size() << endl;
	return 0;
} 
