#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	char c;
	int times;
	node(char _c, int _times) : c(_c), times(_times) {}
};

bool cmp(const node& a, const node & b) {
	return a.times > b.times;
}
class Solution {
public:
	string frequencySort(string s) {
		vector<node> v;
		for (char c : s) {
			int index = find(c, v);
			if (index != -1) {
				v[index].times++;
			}
			else {
				v.push_back(node(c, 1));
			}
		}

		sort(v.begin(), v.end(), cmp);
		string ans = "";
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].times; j++)
				ans += v[i].c;
		}
		return ans;
	}

	int find(char c, vector<node> &v) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].c == c) return i;
		}
		return -1;
	}
};
//int main() {
//	Solution s;
//	string test = "Aabb";
//	cout << s.frequencySort(test) << endl;
//	return 0;
//}