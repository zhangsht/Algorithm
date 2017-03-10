#include <iostream>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;


		return pathSum(root, 0, sum)
			+ pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int pathSum(TreeNode* root, int cur, int sum) {
		if (!root) return 0;
		int val = cur + root->val;
		return (val == sum) + pathSum(root->left, val, sum) + pathSum(root->right, val, sum);
 	}
};
//
//int main() {
//
//	return 0;
//}