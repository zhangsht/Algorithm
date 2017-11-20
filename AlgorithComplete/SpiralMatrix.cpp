#include "common.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m <= 0) {
        	return result;
		}
		int n = matrix[0].size();
		if (n <= 0) {
			return result;
		}
		int rowBegin = 0;
		int rowEnd = m - 1;
		int colBegin = 0;
		int colEnd = n - 1; 
		while (rowBegin <= rowEnd && colBegin <= colEnd) {
			for (int i = colBegin; i <= colEnd; i++) {
				result.push_back(matrix[rowBegin][i]);
			}
			rowBegin++;
			
			for (int j = rowBegin; j <= rowEnd; j++) {
				result.push_back(matrix[j][colEnd]);
			}
			colEnd--;
			
			if (rowBegin <= rowEnd) {
				for (int i = colEnd; i >= colBegin; i--) {
					result.push_back(matrix[rowEnd][i]);
				}
			}
			rowEnd--;
			
			if (colBegin <= cloEnd) {
				for (int i = rowEnd; i >= rowBegin; i--) {
					result.push_back(matrix[i][colBegin]);
				}
			}
			colBegin++;
			
		}
		return result;
    }
};

int main() {
	Solution solution;
	return 0;
} 
