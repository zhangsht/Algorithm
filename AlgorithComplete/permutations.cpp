#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> row;


		map<int, int> m;
		for (auto num : nums) {
			if (m.find(num) == m.end()) m[num] = 0;
			m[num]++;
		}
		permuteUnique(ans, row, nums.size(), m);
		return ans;
	}

	void permuteUnique(vector<vector<int>> &ans, vector<int>& row,
		int index, map<int, int> &m) {
		if (index <= 0) {
			ans.push_back(row);
			return;
		}
		for (auto &p : m) {
			if (p.second <= 0) continue;
			row.push_back(p.first);
			p.second--;
			permuteUnique(ans, row, index - 1, m);
			row.pop_back();
			p.second++;
		}
	}
};

//int main() {
//	Solution s;
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(2);
//	vector<vector<int>> ans = s.permuteUnique(v);
//	cout << ans.size();
//	for (auto & row : ans) {
//		for (auto num : row)
//			cout << num << ' ';
//		cout << endl;
//	}
//	return 0;
//}