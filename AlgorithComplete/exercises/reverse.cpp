#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		if (x < 0) {
			sign = -1;
			x = -x;
		}
		unsigned long long tmp = 0;
		while (x != 0) {
			tmp = tmp * 10 + x % 10;
			x /= 10;
		}
		long max = 2147483647;
		if (tmp > INT_MAX) return 0;
		else return tmp * sign;
	}
};

//int main() {
//	Solution s;
//	cout << INT_MAX << endl;
//	//cout << s.reverse(1000000003) << endl;
//	return 0;
//}