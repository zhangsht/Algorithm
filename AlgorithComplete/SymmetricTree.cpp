#include "common.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (!root) {
    		return true;
		}
		TreeNode* left;
		TreeNode* right;
		
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()) {
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (NULL == left && right == NULL) {
				continue;
			}
			if (left == NULL || NULL = right) {
				return false;
			}
			if (left->val != right->val) {
				return false;
			}
			q1.push(left->right);
			q1.push(left->left);
			q2.push(right->left);
			q2.push(right->right);
			
		}
		
		return true;
    }
private:
	void checkValue(TreeNode* one, TreeNode* another) {
		if (one)
	}
	void getInOrder(vector<int> &values, TreeNode* root) {
		if (!root) {
			return;
		}
		getInOrder(values, root->left);
		values.push_back(root->val);
		getInOrder(values, root->right);
	}
};

int main() {
	
}
