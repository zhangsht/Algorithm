#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		long base = 9, digits = 1;
		while (n - base * digits > 0) {
			n -= base * digits;
			base *= 10;
			digits++;
		}

		int index = n % digits;
		if (index == 0) index = digits;
		int number = 1;
		for (int i = 1; i < digits; i++) {
			number *= 10;
		}

		number += (index == digits ? n / digits - 1 : n / digits);

		for (int i = index; i < digits; i++) number /= 10;

		return number % 10;
	}
};

//int main() {
//	Solution s;
//
//	cout << s.findNthDigit(3);
//	return 0;
//}