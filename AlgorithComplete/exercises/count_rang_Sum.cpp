#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (0 == nums.size()) return 0;
		return countRangeSum(nums, 0, nums.size() - 1, lower, upper);
	}
private:
	int countRangeSum(vector<int>& nums, int l, int r, int lower, int upper) {
		if (l > r) return 0;
		if (l == r) return (lower <= nums[l] && nums[l] <= upper) ? 1 : 0;

		int m = l + ((r - l) >> 1);
		vector<long> sums;
		sums.push_back(nums[m]);
		for (int i = m - 1; i >= l; --i)
			sums.push_back(nums[i] + sums.back());
		sort(sums.begin(), sums.end());

		long tmp = 0, count = 0;
		for (int i = m + 1; i <= r; ++i)
		{
			tmp += nums[i];
			count += (BinSearch(sums, upper - tmp + 0.5) - BinSearch(sums, lower - tmp - 0.5));
		}

		return countRangeSum(nums, l, m, lower, upper) + countRangeSum(nums, m + 1, r, lower, upper) + count;
	}

	int BinSearch(vector<long> &sums, double target) {
		int l = 0, r = sums.size() - 1;
		while (l <= r)
		{
			int m = l + ((r - l) >> 1);
			if (sums[m] > target) r = m - 1;
			else l = m + 1;
		}
		return r;
	}
};
//int main() {
//
//	system("pause");
//	return 0;
//}