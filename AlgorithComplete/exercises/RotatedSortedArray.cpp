#include "common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) {
        	return -1;
		}
		int n = nums.size();
		int low = 0;
		int high = n - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			if (nums[mid] < nums[high]) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		
		int rotatedIndex = low;
		low = 0;
		high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int relativeMid = (mid + rotatedIndex) % n;
			if (target == nums[relativeMid]) {
				return mid;
			} else if (target > nums[relativeMid]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		
		return -1;
    }
};

int main() {
	return 0;
} 
