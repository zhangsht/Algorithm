#include "integration.h"
/*
 nlog(n) to get longest increasing subsequence
 if a[i] <= a[j] && dp[i] == dp[j]
 we replace a[i] to get longer subsequence
*/
int lengthOfLIS(vector<int>& nums) {
	if (nums.size() <= 0) {
		return 0;
	}
	vector<int> subsequence;
	subsequence.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		auto it = lower_bound(subsequence.begin(), subsequence.end(), nums[i]);
		if (it == subsequence.end()) {
			subsequence.push_back(nums[i]);
		} else {
			*it = nums[i];
		}
	}
	return subsequence.size();
}