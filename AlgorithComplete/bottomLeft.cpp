#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	int findBottomLeftValue(TreeNode* root) {
//		depth = 0;
//		ans = root->val;
//		if (root->left) findBottomLeftValue(root->left, 1);
//		if (root->right) findBottomLeftValue(root->right, 1);
//		return ans;
//	}
//
//private:
//	int depth;
//	int ans;
//	void findBottomLeftValue(TreeNode* root, int d) {
//		if (d > depth) {
//			depth = d;
//			ans = root->val;
//			//cout << "ans: " << ans << endl;
//		}
//		if (root->left) findBottomLeftValue(root->left, d + 1);
//		if (root->right) findBottomLeftValue(root->right, d + 1);
//	}
//};

//class Solution {
//public:
//	bool isBalanced(TreeNode* root) {
//		if (!root) return true;
//		if (abs(findHeight(root->left) - findHeight(root->right)) > 1)
//			return false;
//		return isBalanced(root->left) && isBalanced(root->right);
//	}
//
//private:
//	int findHeight(TreeNode* root) {
//		if (!root) return 0;
//
//		return 1 + max(findHeight(root->left), findHeight(root->right));
//	}
//};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return findHeight(root);
	}
private:
	int findHeight(TreeNode* root) {
		if (!root) return 0;

		return 1 + max(findHeight(root->left), findHeight(root->right));
	}
};
//int main() {
//	TreeNode* root = new TreeNode(2);
//	TreeNode* left = new TreeNode(1);
//	TreeNode* right = new TreeNode(3);
//	root->left = left;
//	root->right = right;
//	Solution s;
//	return 0;
//}