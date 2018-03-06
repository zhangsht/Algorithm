#include <iostream>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	/*void connect(TreeLinkNode *root) {
		if (!root) return;

		if (root->left)
			root->left->next = root->right;
		if (root->right)
			root->right->next = root->next ? root->next->left : NULL;
		connect(root->left);
		connect(root->right);
	}
*/
	void connect(TreeLinkNode *root) {
		TreeLinkNode *head, *cur, *nCur;
		head = nCur = NULL;
		cur = root;
		while (cur) {
			while (cur) {
				if (cur->left) {
					if (nCur) {
						nCur->next = cur->left;
					} else {
						head = cur->left;
					}
					nCur = cur->left;
				}
				if (cur->right) {
					if (nCur) {
						nCur->next = cur->right;
					}
					else {
						head = cur->right;
					}
					nCur = cur->right;
				}
				cur = cur->next;
			}
			cur = head;
			head = nCur = NULL;
		}
	}
};
//int main() {
//
//	return 0;
//}