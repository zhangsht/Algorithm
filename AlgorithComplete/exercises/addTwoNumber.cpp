#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* root = new ListNode(0);
		ListNode* ans = root;
		int val, carry = 0, sum;
		while (l1 && l2) {
			sum = l1->val + l2->val + carry;
			val = sum % 10, carry = sum / 10;
			ans->next = new ListNode(val);
			ans = ans->next;
			l1 = l1->next, l2 = l2->next;
		}
		while (l1) {
			sum = l1->val + carry;
			val = sum % 10, carry = sum / 10;
			ans->next = new ListNode(val);
			ans = ans->next;
			l1 = l1->next;
		}
		while (l2) {
			sum = l2->val + carry;
			val = sum % 10, carry = sum / 10;
			ans->next = new ListNode(val);
			ans = ans->next;
			l2 = l2->next;
		}
		if (carry != 0) {
			ans->next = new ListNode(carry);
		}
		return root->next;
	}
};

//int main() {
//	ListNode* l1 = new ListNode(9);
//	ListNode* l11 = new ListNode(8);
//	l1->next = l11;
//
//	ListNode* l2 = new ListNode(1);
//	Solution s;
//	ListNode* ans = s.addTwoNumbers(l1, l2);
//	while (ans) {
//		cout << ans->val << ' ';
//		ans = ans->next;
//	}
//	cout << endl;
//	return 0;
//}