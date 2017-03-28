#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <limits>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;

		int sign = 1;
		int i = 0;
		for (; i < str.size(); i++) {
			//cout << "str[i]: " << str[i] << endl;
			if (isspace(str[i])) continue;
			if (str[i] == '+') {
				i++;
				break;
			};
			if (str[i] == '-') {
				sign = -1;
				i++;
				break;
			}
			if (isdigit(str[i])) break;
			return 0;
		}
		if (i >= str.size()) return 0;
		long long ans = 0;
		int j = i;
		for (; j < str.size(); j++) {
			if (!isdigit(str[j])) break;
			//cout << "str[i]: " << str[i] << endl;
			ans = ans * 10 + str[j] - '0';
			if (ans > INT_MAX) break;
			//cout << "cal " << ans << endl;
		}
		ans *= sign;
		if (ans > INT_MAX) return INT_MAX;
		else if (ans < INT_MIN) return INT_MIN;
		else return ans;
	}
};
//
//int main() {
//	Solution s;
//
//	cout << s.myAtoi("-2147483649") << endl;
//	return 0;
//}