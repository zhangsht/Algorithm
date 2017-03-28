#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int i = 0, res = 0;
		int len = nums.size();
		long long maxNum = 0;
		while (maxNum < n) {
			if (i < len && nums[i] <= maxNum + 1) {
				maxNum = maxNum + nums[i];
				i++;
			}
			else {
				maxNum += maxNum + 1;
				res++;
			}
		}
		return res;
	}

	int maxProfit(vector<int>& prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1]) {
				res += prices[i] - prices[i - 1];
			}
		}
		return res;
	}
};

int main() {
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(4);
	Solution test;
	cout << test.maxProfit(prices) << endl;
	system("pause");
	return 0;
}