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
	void flatten(TreeNode* root) {
		if (!root) return;
		flatten(root->left);
		flatten(root->right);
		TreeNode* p = root;
		if (!p->left) return;
		p = p->left;
		while (p->right != NULL) {
			p = p->right;
		}
		p->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}
};

int main() {

	return 0;
}