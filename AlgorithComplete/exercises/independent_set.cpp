#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node {
	int value;
	int is_LISS;
	int not_LISS;
	Node *lChild, *rChild;
	Node(int val, int is_, int not_, Node* lc, Node* rc):
		value(val), is_LISS(is_), not_LISS(not_), lChild(lc), rChild(rc) {}
};

int is_LISS(Node*);
int not_LISS(Node*);


int is_LISS(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + not_LISS(root->lChild) + not_LISS(root->rChild);
	}
}

int not_LISS(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return max(is_LISS(root->lChild), not_LISS(root->lChild)) +
			max(is_LISS(root->rChild), not_LISS(root->rChild));
	}
}

int LISS(Node* root) {
	return max(is_LISS(root), not_LISS(root));
}

//int main() {
//	Node* n70 = new Node(70, -1, -1, NULL, NULL);
//	Node* n80 = new Node(80, -1, -1, NULL, NULL);
//	Node* n50 = new Node(50, -1, -1, n70, n80);
//	Node* n40 = new Node(40, -1, -1, NULL, NULL);
//	Node* n20 = new Node(20, -1, -1, n40, n50);
//	Node* n60 = new Node(60, -1, -1, NULL, NULL);
//	Node* n30 = new Node(30, -1, -1, NULL, n60);
//	Node* n10 = new Node(10, -1, -1, n20, n30);
//
//	cout << LISS(n10) << endl;
//	system("pause");
//	return 0;
//}