#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (int i = 1, len = nums.size(); i <= len; i++) {
			result.push_back(i);
		}
		for (int i = 0, len = nums.size(); i < len; i++) {
			if (result[nums[i] - 1] == nums[i]) {
				result[nums[i] - 1] = 0;
			}
		}

		vector<int>::iterator it;
		for (it = result.begin(); it != result.end();) {
			if (*it == 0) {
				it = result.erase(it);
			} else {
				++it;
			}
		}

		return  result;
	}
};

//int main() {
//	Solution s;
//	vector<int> test;
//	for (int i = 0; i < 10; i++) {
//		int a = rand() % 10 + 1;
//		test.push_back(a);
//		cout << a << ' ';
//	}
//	vector<int> ans = s.findDisappearedNumbers(test);
//	for (int a : ans) {
//		cout << a << ' ';
//	}
//	cout << '\n';
//	return 0;
//}