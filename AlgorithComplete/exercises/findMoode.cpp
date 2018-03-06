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
	vector<int> findMode(TreeNode* root) {
		tmpCount = 0, maxCount = 0;
		curVal = 0;
		inOrder(root);

		return ans;
	}

	void inOrder(TreeNode* root) {
		if (!root) return;
		inOrder(root->left);
		tmpCount++;
		if (root->val != curVal) {
			curVal = root->val;
			tmpCount = 1;
		}

		if (tmpCount > maxCount) {
			ans.clear();
			maxCount = tmpCount;
			ans.push_back(root->val);
		} else if (tmpCount == maxCount) {
			ans.push_back(root->val);
		}
		inOrder(root->right);
	}

private:
	int tmpCount, maxCount;
	int curVal;
	vector<int> ans;
};
//
//int main() {
//
//	return 0;
//}