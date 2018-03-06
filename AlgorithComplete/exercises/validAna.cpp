#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;

		int character[26] = {};
		for (int i = 0; i < t.size(); i++) {
			character[s[i] - 'a']++;
			character[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
			if (character[i]) return false;
		return true;
	}*/

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		int index = 0;
		unordered_map<string, int> um;
		for (int i = 0, lens = strs.size(); i < lens; i++) {
			int character[26] = {};
			for (int j = 0, len = strs[i].size(); j < len; j++) {
				character[strs[i][j] - 'a']++;
			}
			string str = "";
			for (int k = 0; k < 26; k++) {
				stringstream ss;
				ss << character[k];
				string t;
				ss >> t;
				str += t;
			}
			if (um.find(str) != um.end()) {
				ans[um[str]].push_back(strs[i]);
			} else {
				ans.resize(index + 1);
				um[str] = index;
				ans[index].push_back(strs[i]);
				index++;
			}
		}
		return ans;
	}
};

//int main() {
//	Solution ss;
//	string s = "sddsf";
//	string t = "ssdddf";
//	vector<string> v;
//	v.push_back(s);
//	v.push_back(t);
//	vector<vector<string>> ans = ss.groupAnagrams(v);
//	for (int i = 0; i < ans.size(); i++) {
//		for (int j = 0; j < ans[i].size(); j++)
//			cout << ans[i][j] << ' ';
//		cout << endl;
//	}
//	cout << ans.size() << endl;
//	return 0;
//}