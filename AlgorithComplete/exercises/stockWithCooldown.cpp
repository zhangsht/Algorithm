#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int len = prices.size();
		vector<int> s0(len, 0);
		vector<int> s1(len, 0);
		vector<int> s2(len, 0);
		s0[0] = 0;
		s1[0] = -prices[0];
		s2[0] = INT_MIN;
		for (int i = 1; i < len; i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max(s0[len - 1], s2[len - 1]);
	}
};

//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(0);
//	v.push_back(2);
//
//	Solution s;
//	cout << s.maxProfit(v) << endl;
//	return 0;
//}