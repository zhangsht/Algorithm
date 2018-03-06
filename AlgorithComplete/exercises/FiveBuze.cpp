#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ans;
		string tmp;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0) {
				if (i % 5 == 0) {
					tmp = "FizzBuzz";
					ans.push_back(tmp);
				} else {
					tmp = "Fizz";
					ans.push_back(tmp);
				}
			} else if (i % 5 == 0) {
				tmp = "Buzz";
				ans.push_back(tmp);
			} else {
				tmp = to_string(i);
				ans.push_back(tmp);
			}
		}
		return ans;
	}
};

//int main() {
//	Solution s;
//	vector<string> ans = s.fizzBuzz(15);
//	for (string s : ans) {
//		cout << s << endl;
//	}
//
//	return 0;
//}