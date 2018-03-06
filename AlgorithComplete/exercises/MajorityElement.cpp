#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

//class Solution {
//public:
//	vector<int> majorityElement(vector<int>& nums) {
//		vector<int> result;
//
//		int cnt1 = 0, cnt2 = 0;
//		int a = 0, b = 1;
//		for (auto num : nums) {
//			if (a == num) {
//				cnt1++;
//			} else if (b == num){
//				cnt2++;
//			} else if (cnt1 == 0) {
//				a = num;
//				cnt1++;
//			} else if (cnt2 == 0) {
//				b = num;
//				cnt2++;
//			} else {
//				cnt1--;
//				cnt2--;
//			}
//		}
//
//		cnt1 = 0, cnt2 = 0;
//		for (auto num : nums) {
//			if (num == a) cnt1++;
//			else if (num == b) cnt2++;
//		}
//
//		if (cnt1 > nums.size() / 3) result.push_back(a);
//		if (cnt2 > nums.size() / 3) result.push_back(b);
//		return result;
//	}
//};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int result;

		int a = 0;
		int cnt = 0;
		for (auto num : nums) {
			if (a == num) cnt++;
			else if (cnt == 0) {
				a = num;
				cnt++;
			} else cnt--;
		}
		return a;
	}
};

//int main() {
//	Solution s;
//	vector<int> v;
//	srand(time(NULL));
//	/*for (int i = 0; i < 3; i++) {
//		v.push_back(rand() % 4);
//	}
//	for (int i = 0; i < 4; i++) {
//		v.push_back(rand() % 4);
//	}
//	for (int i = 0; i < 3; i++) {
//		v.push_back(rand() % 4);
//	}
//	for (auto num : v) {
//		cout << num << ' ';
//	}
//	cout << endl;*/
//	v.push_back(int(3));
//	v.push_back(int(0));
//	v.push_back(int(3));
//	v.push_back(int(4));
//
//	vector<int> ans = s.majorityElement(v);
//	for (auto num : ans) {
//		cout << num << ' ';
//	}
//	return 0;
//}