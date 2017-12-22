#include "common.h" 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
        	return head;
		}
		ListNode* newHead = new ListNode(-1);
		newHead->next = head;
		
		ListNode* fast = newHead;
		ListNode* slow = newHead;
		for (int i = 0; i < n; i++) {
			if (fast != NULL) {
				fast = fast->next;
			}
		}
		while (fast->next != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
		
		slow->next = slow->next->next;
		return newHead->next;
    }
};

int main() {
	return 0;
} 
