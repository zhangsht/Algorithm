#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;


//class Solution {
//public:
//	bool isPalindrome(int x) {
//		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
//		int sum = 0;
//		while (x > sum) {
//			sum = sum * 10 + x % 10;
//			x /= 10;
//		}
//		return (x == sum) || (x == sum / 10);
//	}
//
//	//string longestCommonPrefix(vector<string>& strs) {
//	//	if (strs.size() < 1) return string("");
//	//	string ans = strs[0];
//	//	for (int i = 1; i < strs.size(); i++) {
//	//		ans = commonPrefix(ans, strs[i]);
//	//	}
//	//	return ans;
//	//}
//	bool isValid(string s) {
//		if (!s.size()) return true;
//
//		map<char, char> parenthese;
//		parenthese['}'] = '{';
//		parenthese[']'] = '[';
//		parenthese[')'] = '(';
//
//		stack<char> brackets;
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
//				brackets.push(s[i]);
//			} else {
//				if (!brackets.empty() && parenthese[s[i]] == brackets.top()) {
//					brackets.pop();
//				} else return false;
//			}
//		}
//		return brackets.empty();
//	}
//private:
//	string commonPrefix(string& a, string& b) {
//		int len = min(a.size(), b.size());
//		for (int i = 0; i < len; i++) {
//			if (a[i] != b[i]) {
//				return a.substr(0, i);
//			}
//		}
//		return a.substr(0, len);
//	}
//};

//int main() {
//	Solution s;
//	vector<string> v;
//	string str = "()[]{}";
//	cout << s.isValid(str) << endl;
//	return 0;
//}