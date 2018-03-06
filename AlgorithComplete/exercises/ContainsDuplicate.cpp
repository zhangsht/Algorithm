#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		/*for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j <= i + k && j < nums.size(); j++) {
				if (nums[i] == nums[j]) {
					return true;
				}
			}
		}
		return false;*/

		if (nums.size() < 2 || k <= 0) return false;
		map<int, int> contain;
		contain[nums[0]] = 0;
		for (int i = 1, len = nums.size(); i < len; i++) {
			if (contain.find(nums[i]) != contain.end()) {
				if (i - contain[nums[i]] <= k) {
					return true;
				} else contain[nums[i]] = i;
			}
			else contain[nums[i]] = i;
		}
		return false;
	}
};

//int main() {
//	int a[4] = { 1, 0,1, 1};
//	vector<int> nums(a, a + 4);
//	Solution s;
//	cout << s.containsNearbyDuplicate(nums, 2) << endl;
//	system("pause");
//	return 0;
//}