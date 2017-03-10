#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* tail = new ListNode(0);
		ListNode* ans = tail;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return ans->next;
	}


	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (j >= 0) {
			nums1[k--] = i >= 0 && nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
		}
	}

	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int pre = nums[0];
		vector<int>::iterator it;
		for (it = nums.begin() + 1; it != nums.end();) {
			if (*it == pre) {
				it = nums.erase(it);
			}
			else {
				pre = *it;
				it++;
			}
		}

		return nums.size();
	}

	int removeElement(vector<int>& nums, int val) {
		if (!nums.size()) return 0;

		int len = nums.size();
		for (int i = 0; i < len;) {
			if (val == nums[i]) {
				nums[i] = nums[--len];
			}
			else i++;
		}
		return len;
	}


	int searchInsert(vector<int>& nums, int target) {
		if (!nums.size() || target <= nums[0]) return 0;

		int i = 0;
		while (i < nums.size() && target > nums[i]) {
			i++;
		}
		return i;
	}


	bool isBadVersion(int version) {
		return false;
	}

	int firstBadVersion(int n) {
		int low = 0, high = n;
		while (low + 1 < high) {
			int mid = low + (high - low) / 2;
			if (isBadVersion(mid)) {
				high = mid;
			}
			else low = mid;
		}
		return high;
	}
};
//
//int main() {
//	/*vector<int> v;
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(5);
//	v.push_back(6);*/
//
//	Solution s;
//	cout << s.firstBadVersion(10) << endl;
//	return 0;
//}