#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (!nums.size()) return NULL;
		if (nums.size() == 1) {
			
			return new TreeNode(nums[0]);
		}

		return ToBST(nums, 0, nums.size());
	}

	TreeNode* ToBST(vector<int>& nums, int low, int high) {
		if (low < high) {
			int mid = low + (high - low) / 2;
			TreeNode* root = new TreeNode(nums[mid]);
			TreeNode* left = ToBST(nums, low, mid);
			TreeNode* right = ToBST(nums, mid + 1, high);
			root->left = left;
			root->right = right;
			return root;
		}
		else return NULL;
	}
};

//int main() {
//	Solution s;
//	vector<int> nums;
//	//nums.push_back(int(0));
//	TreeNode* root = s.sortedArrayToBST(nums);
//	if (!root) cout << "test" << endl;
//	else cout << root->val << endl;
//	return 0;
//}