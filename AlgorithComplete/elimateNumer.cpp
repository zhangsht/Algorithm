#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		if (n < 3) return n;

		stack<int> left, right;
		int i = n;
		while (i >= 1) {
			left.push(i);
			i--;
		}
		while (left.size() > 1) {
			//cout << left.top() << ' ';
			left.pop();
			//cout << left.top() << ' ';
			right.push(left.top());
			left.pop();
			if (left.size() == 1) left.pop();
			if (left.empty()) {
				left = right;
				while (!right.empty()) right.pop();
			}
		}
		cout << endl;
		return left.top();
	}
};

//int main() {
//	Solution s;
//	cout << s.lastRemaining(8) << endl;
//	return 0;
//}