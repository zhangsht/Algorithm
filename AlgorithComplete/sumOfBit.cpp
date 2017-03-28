#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int sum = 0;
		while (b) {
			sum = a ^ b;
			b = (a & b) << 1;
			a = sum;
		}
		return sum;
	}

	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int a : nums) {
			ans ^= a;
		}
		return ans;
	}
};

//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//
//	v.push_back(1);
//	Solution s;
//	cout << s.singleNumber(v) << endl;
//	return 0;
//}