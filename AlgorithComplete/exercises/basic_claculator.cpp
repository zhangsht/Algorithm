#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> nums, ops;
		int num = 0;
		int res = 0;
		int sign = 1;
		for (char c : s) {
			if (isdigit(c)) {
				num = num * 10 + c - '0';
			} else {
				res += sign * num;
				num = 0;
				if (c == '+') sign = 1;
				else if (c == '-') sign = -1;
				else if (c == '(') {
					nums.push(res);
					ops.push(sign);
					res = 0;
					sign = 1;
				}
				else if (c == ')' && ops.size()) {
					res = ops.top() * res + nums.top();
					ops.pop();
					nums.pop();
				}
			}
		}
		res += sign * num;
		return res;
	}
};
//
//int main() {
//
//	system("pause");
//	return 0;
//}