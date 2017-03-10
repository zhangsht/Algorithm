#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return 0;

		sort(nums.begin(), nums.end());
		int tot = (nums[0] + nums[1] + nums[2]);
		int cur = abs(tot - target);
		int ans = tot;
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				tot = nums[i] + nums[j] + nums[k];
				if (cur > abs(tot - target)) {
					cur = abs(tot - target);
					ans = tot;
				}
				if (tot < target) j++;
				else k--;

			}
		}
		return ans;
	}
};

//int main() {
//	Solution s;
//	//  S = {-1 2 1 -4}, and target = 1.
//	vector<int> v;
//	v.push_back(-1);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(-4);
//
//	cout << s.threeSumClosest(v, 1) << endl;
//	return 0;
//}