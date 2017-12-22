#include "common.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
    	if (m > n) {
    		return uniquePaths(n, m);
		}
        vector<int> cur(m, 1);
//		vector<vector<int> > matrix(m, vector(n, 1));
		for (int j = ; j < n; j++) {
			for (int i = 0; i < m; i++) {
				cur[i] += cur[i - 1];
			}
		}
		return cur[m - 1];
    }
};

int main() {
	Solution solution;
	return 0;
} 
