#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
        addingPair(result, "", n, 0);
        return result;
    }

private:
	addingPair(vector<string>& result, string cur, int n, int m) {
		if (n == 0 && m == 0) {
			result.push_back(cur);
			return;
		}
		
		if (m > 0) {
			addingPair(result, cur + ')', n, m - 1);
		}
		if (n > 0) {
			addingPair(result, cur + '(', n - 1, m + 1);
		}
	}
};
